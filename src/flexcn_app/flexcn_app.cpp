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

/*! \file flexcn_app.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include "flexcn_app.hpp"

#include <unistd.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/posix_time/time_formatters.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <chrono>

#include "3gpp_29.500.h"
#include "api_conversions.hpp"
#include "logger.hpp"
#include "flexcn_client.hpp"
#include "flexcn_config.hpp"

using namespace oai::flexcn::app;
using namespace oai::flexcn_server::model;
using namespace std::chrono;

extern flexcn_app* flexcn_app_inst;
extern flexcn_config flexcn_cfg;
flexcn_client* flexcn_client_inst = nullptr;

//------------------------------------------------------------------------------
flexcn_app::flexcn_app(const std::string& config_file, flexcn_event& ev, int cn_version)
    : m_event_sub(ev),
      m_subscription_id2flexcn_subscription(){
  Logger::flexcn_app().startup("Starting...");

  try {
    flexcn_client_inst = new flexcn_client(ev);
  } catch (std::exception& e) {
    Logger::flexcn_app().error("Cannot create FLEXCN_APP: %s", e.what());
    throw;
  }
  Logger::flexcn_app().startup("Started");
}

//------------------------------------------------------------------------------
flexcn_app::~flexcn_app() {
  Logger::flexcn_app().debug("Delete FLEXCN_APP instance...");
  for (auto i : connections) {
    if (i.connected()) i.disconnect();
  }

  if (flexcn_client_inst) delete flexcn_client_inst;
}

//------------------------------------------------------------------------------
void flexcn_app::generate_uuid() {
  flexcn_instance_id = to_string(boost::uuids::random_generator()());
}

//------------------------------------------------------------------------------
void flexcn_app::subscribe_task_tick(uint64_t ms) {
  struct itimerspec its;
  its.it_value.tv_sec  = 20;  // seconds
  its.it_value.tv_nsec = 0;   // 100 * 1000 * 1000; //100ms

  const uint64_t interval =
      its.it_value.tv_sec * 1000 +
      its.it_value.tv_nsec / 1000000;  // convert sec, nsec to msec

  Logger::flexcn_app().debug("subscribe task_tick: %d", ms);
  m_event_sub.subscribe_task_tick(
      boost::bind(&flexcn_app::handle_heartbeart_timeout, this, _1), interval,
      ms % 20000);
}

//------------------------------------------------------------------------------
void flexcn_app::handle_heartbeart_timeout(uint64_t ms) {
  Logger::flexcn_app().info("handle_heartbeart_timeout %d", ms);
}

//------------------------------------------------------------------------------
void flexcn_app::generate_ev_subscription_id(std::string& sub_id) {
  sub_id = std::to_string(evsub_id_generator.get_uid());
}

//------------------------------------------------------------------------------
evsub_id_t flexcn_app::generate_ev_subscription_id() {
  return evsub_id_generator.get_uid();
}

//------------------------------------------------------------------------------
void flexcn_app::get_subscription_list(
    const std::string& profile_id, const uint8_t& notification_type,
    std::vector<std::string>& uris) const {
 
 }