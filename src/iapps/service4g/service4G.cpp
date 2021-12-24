/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file service4G.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include "service4G.hpp"
#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"
#ifdef __linux__
#include <vector>
#include <signal.h>
#include <unistd.h>
#endif

#define PISTACHE_SERVER_MAX_PAYLOAD 32768

using namespace oai::flexcn_server::api;

void Service4G::init(size_t thr) {
  auto opts = Pistache::Http::Endpoint::options().threads(thr);
  opts.flags(Pistache::Tcp::Options::ReuseAddr);
  opts.maxRequestSize(PISTACHE_SERVER_MAX_PAYLOAD);
  m_httpEndpoint->init(opts);
  m_northBound4GApiImpl->init();
}

void Service4G::start() {
  Logger::flexcn_api_server().info("HTTP1 server started");
  m_httpEndpoint->setHandler(m_router->handler());
  m_httpEndpoint->serve();
}

void Service4G::shutdown() {
  m_httpEndpoint->shutdown();
}

int Service4G::run() {
   start();
}


