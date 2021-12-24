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

/*! \file service4G.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_SERVICE4G_HPP_SEEN
#define FILE_SERVICE4G_HPP_SEEN

#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"
#ifdef __linux__
#include <vector>
#include <signal.h>
#include <unistd.h>
#endif

#include "iApp.hpp"
#include "Bearer.h"

#include "NorthBound4GApiImpl.h"
#include "app4G.hpp"

using namespace oai::flexcn_server::model;
using namespace oai::flexcn_server::api;


class Service4G : public iApp_api {
  public:
    Service4G(Pistache::Address address, std::shared_ptr<Pistache::Rest::Router> router, const std::string& db_addr)
      : iApp_api(), m_httpEndpoint(std::make_shared<Pistache::Http::Endpoint>(address)), m_router(router) {
    m_address = address.host() + ":" + (address.port()).toString();

    m_app4G = std::make_shared<App4G>(db_addr);
    m_northBound4GApiImpl = std::make_shared<NorthBound4GApiImpl>(
        m_router,m_app4G);

    // change according to the build's options
    
    
  }
  void init(size_t thr = 1);
  void start();
  void shutdown();
  std::string name() const {
          return "Service_4G";
      }
  int run();
  ~Service4G() {
  }
  
  private:
    std::shared_ptr<Pistache::Http::Endpoint> m_httpEndpoint;
    std::shared_ptr<Pistache::Rest::Router> m_router;
    std::shared_ptr<NorthBound4GApiImpl> m_northBound4GApiImpl;
    std::string m_address;
    std::shared_ptr<App4G> m_app4G;

};

#endif
