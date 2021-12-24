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

/*! \file flexcn_profile.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#include "flexcn_profile.hpp"

#include <unistd.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "api_conversions.hpp"
#include "logger.hpp"
#include "string.hpp"

using namespace std;
using namespace oai::flexcn::app;

//------------------------------------------------------------------------------
void flexcn_profile::set_nf_instance_id(const std::string& instance_id) {
  nf_instance_id = instance_id;
}

//------------------------------------------------------------------------------
void flexcn_profile::get_nf_instance_id(std::string& instance_id) const {
  instance_id = nf_instance_id;
}

//------------------------------------------------------------------------------
std::string flexcn_profile::get_nf_instance_id() const {
  return nf_instance_id;
}

//------------------------------------------------------------------------------
void flexcn_profile::set_nf_instance_name(const std::string& instance_name) {
  nf_instance_name = instance_name;
}

//------------------------------------------------------------------------------
void flexcn_profile::get_nf_instance_name(std::string& instance_name) const {
  instance_name = nf_instance_name;
}

//------------------------------------------------------------------------------
std::string flexcn_profile::get_nf_instance_name() const {
  return nf_instance_name;
}

//------------------------------------------------------------------------------
void flexcn_profile::set_nf_type(const nf_type_t& type) {
  nf_type = type;
}

//------------------------------------------------------------------------------
nf_type_t flexcn_profile::get_nf_type() const {
  return nf_type;
}

//------------------------------------------------------------------------------
void flexcn_profile::set_nf_status(const std::string& status) {
  Logger::flexcn_app().debug("Set NF status to %s", status.c_str());
  std::unique_lock lock(heartbeart_mutex);
  nf_status = status;
}

//------------------------------------------------------------------------------
void flexcn_profile::get_nf_status(std::string& status) const {
  status = nf_status;
}

//------------------------------------------------------------------------------
std::string flexcn_profile::get_nf_status() const {
  return nf_status;
}

//------------------------------------------------------------------------------
void flexcn_profile::set_nf_heartBeat_timer(const int32_t& timer) {
  heartBeat_timer = timer;
}

//------------------------------------------------------------------------------
void flexcn_profile::get_nf_heartBeat_timer(int32_t& timer) const {
  timer = heartBeat_timer;
}

//------------------------------------------------------------------------------
int32_t flexcn_profile::get_nf_heartBeat_timer() const {
  return heartBeat_timer;
}



//------------------------------------------------------------------------------
void flexcn_profile::display() {
  Logger::flexcn_app().debug("NF instance info");
  Logger::flexcn_app().debug("\tInstance ID: %s", nf_instance_id.c_str());
  Logger::flexcn_app().debug("\tInstance name: %s", nf_instance_name.c_str());
  Logger::flexcn_app().debug(
      "\tInstance type: %s", nf_type_e2str[nf_type].c_str());
  Logger::flexcn_app().debug("\tStatus: %s", nf_status.c_str());
  Logger::flexcn_app().debug("\tHeartBeat timer: %d", heartBeat_timer);
}

//------------------------------------------------------------------------------
bool flexcn_profile::replace_profile_info(
    const std::string& path, const std::string& value) {
  Logger::flexcn_app().debug(
      "Replace member %s with new value %s", path.c_str(), value.c_str());
  if (path.compare("nfInstanceName") == 0) {
    nf_instance_name = value;
    return true;
  }

  if (path.compare("nfStatus") == 0) {
    nf_status = value;
    return true;
  }

  if (path.compare("nfType") == 0) {
    nf_type = api_conv::string_to_nf_type(value);
    return true;
  }

  if (path.compare("heartBeatTimer") == 0) {
    try {
      heartBeat_timer = std::stoi(value);
      return true;
    } catch (const std::exception& err) {
      Logger::flexcn_app().debug("Bad value!");
      return false;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
bool flexcn_profile::add_profile_info(
    const std::string& path, const std::string& value) {
  Logger::flexcn_app().debug(
      "Add an array element (value, array member), or a new member (value, "
      "member):  %s, %s",
      value.c_str(), path.c_str());

  // update an existing member
  if (path.compare("nfInstanceName") == 0) {
    nf_instance_name = value;
    return true;
  }

  if (path.compare("nfStatus") == 0) {
    nf_status = value;
    return true;
  }

  if (path.compare("nfType") == 0) {
    nf_type = api_conv::string_to_nf_type(value);
    return true;
  }

  if (path.compare("heartBeatTimer") == 0) {
    try {
      heartBeat_timer = std::stoi(value);
      return true;
    } catch (const std::exception& err) {
      Logger::flexcn_app().debug("Bad value!");
      return false;
    }
  }

  return false;
}

//------------------------------------------------------------------------------
bool flexcn_profile::remove_profile_info(const std::string& path) {
  Logger::flexcn_app().debug(
      "Remove an array element or a member: %s", path.c_str());
  if (path.compare("nfInstanceName") == 0) {
    nf_instance_name = "";
    return true;
  }

  if (path.compare("nfStatus") == 0) {
    nf_status = "";
    return true;
  }

  if (path.compare("nfType") == 0) {
    nf_type = NF_TYPE_UNKNOWN;
    return true;
  }

  if (path.compare("heartBeatTimer") == 0) {
    heartBeat_timer = 0;
    return true;
  }

  Logger::flexcn_app().debug("Member (%s) not found!", path.c_str());
  return false;
}

//------------------------------------------------------------------------------
void flexcn_profile::to_json(nlohmann::json& data) const {
  data["nfInstanceId"]   = nf_instance_id;
  data["nfInstanceName"] = nf_instance_name;
  data["nfType"]         = nf_type_e2str[nf_type];
  data["nfStatus"]       = nf_status;
  data["heartBeatTimer"] = heartBeat_timer;

}

//------------------------------------------------------------------------------
void flexcn_profile::subscribe_heartbeat_timeout_nfregistration(uint64_t ms) {
  // For the first timeout, we use 2*HEART_BEAT_TIMER as interval
  struct itimerspec its;
  its.it_value.tv_sec  = 2 * HEART_BEAT_TIMER;  // seconds
  its.it_value.tv_nsec = 0;                     // 100 * 1000 * 1000; //100ms
  const uint64_t interval =
      its.it_value.tv_sec * 1000 +
      its.it_value.tv_nsec / 1000000;  // convert sec, nsec to msec

  Logger::flexcn_app().debug(
      "Subscribe to the HeartBeartTimer expire event (after NF "
      "registration): interval %d, current time %ld",
      2 * HEART_BEAT_TIMER, ms);
  first_hb_connection = m_event_sub.subscribe_task_tick(
      boost::bind(
          &flexcn_profile::handle_heartbeart_timeout_nfregistration, this, _1),
      interval, ms + interval);
}

//------------------------------------------------------------------------------
void flexcn_profile::subscribe_heartbeat_timeout_nfupdate(uint64_t ms) {
  struct itimerspec its;
  its.it_value.tv_sec  = HEART_BEAT_TIMER;  // Second
  its.it_value.tv_nsec = 0;                 // 100 * 1000 * 1000; //100ms
  const uint64_t interval =
      its.it_value.tv_sec * 1000 +
      its.it_value.tv_nsec / 1000000;  // convert sec, nsec to msec

  Logger::flexcn_app().debug(
      "Subscribe to HeartbeatTimer expire event (after NF update): interval "
      "%d, current time %ld",
      HEART_BEAT_TIMER, ms);

  if (first_update) {
    ms = ms + 2000;  // Not a realtime NF: adding 2000ms interval between the
                     // expected NF update message and HBT
    task_connection = m_event_sub.subscribe_task_tick(
        boost::bind(&flexcn_profile::handle_heartbeart_timeout_nfupdate, this, _1),
        interval, ms + interval);
    first_update = false;
  }
}

//------------------------------------------------------------------------------
bool flexcn_profile::unsubscribe_heartbeat_timeout_nfupdate() {
  if (task_connection.connected()) {
    task_connection.disconnect();
    Logger::flexcn_app().debug(
        "Unsubscribe to the Heartbeat Timer timeout event (after NF Update)");
    return true;
  } else {
    return false;
  }
}

//------------------------------------------------------------------------------
bool flexcn_profile::unsubscribe_heartbeat_timeout_nfregistration() {
  if (first_hb_connection.connected()) {
    first_hb_connection.disconnect();
    Logger::flexcn_app().debug(
        "Unsubscribe to the first Heartbeat Timer timeout event (after NF "
        "Registration)");
    return true;
  } else {
    return false;
  }
}

//------------------------------------------------------------------------------
void flexcn_profile::handle_heartbeart_timeout(uint64_t ms) {
  Logger::flexcn_app().info(
      "\nHandle heartbeart timeout, NF instance ID %s, time %d",
      nf_instance_id.c_str(), ms);
  set_nf_status("SUSPENDED");
}

//------------------------------------------------------------------------------
void flexcn_profile::handle_heartbeart_timeout_nfregistration(uint64_t ms) {
  Logger::flexcn_app().info(
      "\nHandle the first Heartbeat timeout, NF instance ID %s, current time "
      "%d",
      nf_instance_id.c_str(), ms);
  // Set status to SUSPENDED and unsubscribe to the HBT
  if (!is_updated) {
    set_nf_status("SUSPENDED");
  }

  set_status_updated(false);
  unsubscribe_heartbeat_timeout_nfregistration();
}

//------------------------------------------------------------------------------
void flexcn_profile::handle_heartbeart_timeout_nfupdate(uint64_t ms) {
  uint64_t current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();
  Logger::flexcn_app().info(
      "\nHandle heartbeart timeout (NF update), NF instance ID %s, time %ld, "
      "current "
      "ms %ld",
      nf_instance_id.c_str(), ms, current_ms);
  if (!is_updated) {
    set_nf_status("SUSPENDED");
  }
  set_status_updated(false);
}

//------------------------------------------------------------------------------
void flexcn_profile::set_status_updated(bool status) {
  std::unique_lock lock(heartbeart_mutex);
  is_updated = status;
}
