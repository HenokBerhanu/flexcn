/*
 * Copyright (c) 2017 Sprint
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "logger.hpp"
#include "flexcn-api-server.h"
#include "flexcn_app.hpp"
#include "flexcn_client.hpp"
#include "options.hpp"
#include "pid_file.hpp"

#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"

#include <signal.h>
#include <stdint.h>
#include <stdlib.h>  // srand
#include <unistd.h>  // get_pid(), pause()
#include <iostream>
#include <thread>

#ifdef WITH_4G
#include "service4g/service4G.hpp"
#endif

#ifdef WITH_5G_SMF
#include "smf5g/smf_app.hpp"
#endif

#ifdef WITH_5G_AMF
#include "amf5g/amf_app.hpp"
#endif

using namespace oai::flexcn::app;
using namespace util;
using namespace std;

flexcn_app* flexcn_app_inst = nullptr;
flexcn_config flexcn_cfg;
FLEXCNApiServer* api_server = nullptr;


// list of all iapps

#ifdef WITH_4G
// service 4G
Service4G* service4GApp = nullptr;
#pragma message "4G FEATURE IS ENABLED."
#endif

#ifdef WITH_5G_SMF
// SMF 5G app
std::shared_ptr<SMFApp> smf5GApp = nullptr;
#pragma message "5G SMF FEATURE IS ENABLED."
#endif

#ifdef WITH_5G_AMF
// AMF 5G app
std::shared_ptr<AMFApp> amf5GApp = nullptr;
#pragma message "5G AMF FEATURE IS ENABLED."
#endif


//------------------------------------------------------------------------------
void my_app_signal_handler(int s) {
  std::cout << "Caught signal " << s << std::endl;
  Logger::system().startup("exiting");
  std::cout << "Freeing Allocated memory..." << std::endl;
  if (api_server) {
    api_server->shutdown();
    delete api_server;
    api_server = nullptr;
  }
  std::cout << "FLEXCN API Server memory done" << std::endl;

  if (flexcn_app_inst) {
    delete flexcn_app_inst;
    flexcn_app_inst = nullptr;
  }

  // release the iApp HERE

#ifdef WITH_4G  
  // 4G app
  if (service4GApp) {
    service4GApp->shutdown();
    delete service4GApp;
    service4GApp = nullptr;
  }
#endif

  std::cout << "FLEXCN APP memory done" << std::endl;
  std::cout << "Freeing allocated memory done" << std::endl;

  exit(0);
}

//------------------------------------------------------------------------------
int main(int argc, char** argv) {
  srand(time(NULL));

  // Command line options
  if (!Options::parse(argc, argv)) {
    std::cout << "Options::parse() failed" << std::endl;
    return 1;
  }

  // Logger
  Logger::init("flexcn", Options::getlogStdout(), Options::getlogRotFilelog());
  Logger::flexcn_app().startup("Options parsed");

  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = my_app_signal_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);

  // Config
  flexcn_cfg.load(Options::getlibconfigConfig());
  flexcn_cfg.display();

  // Event subsystem
  flexcn_event ev;

  // FLEXCN application layer
  flexcn_app_inst = new flexcn_app(Options::getlibconfigConfig(), ev, flexcn_cfg.core_network_version);

  std::string flexcn_ip_v4 = std::string(inet_ntoa(*((struct in_addr*) &flexcn_cfg.sbi.addr4)));

#ifdef WITH_5G_SMF
  //5g app launch here
  smf5GApp = std::make_shared<SMFApp>(flexcn_ip_v4, flexcn_cfg.sbi.port, 
                                          flexcn_cfg.smf_info.nf_addr_v4, 
                                          flexcn_cfg.smf_info.port);
#endif

#ifdef WITH_5G_AMF
  //5g app launch here
  amf5GApp = std::make_shared<AMFApp>(flexcn_ip_v4, flexcn_cfg.sbi.port, 
                          flexcn_cfg.amf_info.nf_addr_v4, flexcn_cfg.smf_info.port);
#endif

  // Task Manager
  task_manager tm(ev);
  std::thread task_manager_thread(&task_manager::run, &tm);

  // PID file
  // Currently hard-coded value. TODO: add as config option.
  string pid_file_name = get_exe_absolute_path("/var/run", flexcn_cfg.instance);
  if (!is_pid_file_lock_success(pid_file_name.c_str())) {
    Logger::flexcn_app().error("Lock PID file %s failed\n", pid_file_name.c_str());
    exit(-EDEADLK);
  }

  Pistache::Address addr(
      flexcn_ip_v4, Pistache::Port(flexcn_cfg.sbi.port));
  std::shared_ptr<Pistache::Rest::Router> router  = std::make_shared<Pistache::Rest::Router>();

#ifdef WITH_4G  
  //iApps launch
  service4GApp = new Service4G(addr, router, "192.168.70.131");
  service4GApp->init(2);
  std::thread service4G_manager(&Service4G::run, service4GApp);
  service4G_manager.join();
#endif

  // FLEXCN Pistache API server (HTTP1)
  api_server = new FLEXCNApiServer(addr);
#ifdef WITH_5G_SMF  
  // api_server->set_smf_app(smf5GApp);
  api_server->set_monitor_app(smf5GApp);
#endif

#ifdef WITH_5G_AMF  
  // api_server->set_amf_app(amf5GApp);
  api_server->set_monitor_app(amf5GApp);
#endif

  api_server->init(2);
  std::thread flexcn_manager(&FLEXCNApiServer::start, api_server);
  flexcn_manager.join();

  FILE* fp             = NULL;
  std::string filename = fmt::format("/tmp/flexcn_{}.status", getpid());
  fp                   = fopen(filename.c_str(), "w+");
  fprintf(fp, "STARTED\n");
  fflush(fp);
  fclose(fp);

  pause();
  return 0;
}
