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

/*! \file flexcn_subscription.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#include "flexcn_subscription.hpp"

#include <boost/date_time/posix_time/time_formatters.hpp>
#include <nlohmann/json.hpp>

#include "logger.hpp"

using namespace oai::flexcn::app;

//------------------------------------------------------------------------------
void flexcn_subscription::set_subscription_id(const std::string& sub) {
  subscription_id = sub;
}

//------------------------------------------------------------------------------
void flexcn_subscription::get_subscription_id(std::string& sub) const {
  sub = subscription_id;
}

//------------------------------------------------------------------------------
std::string flexcn_subscription::get_subscription_id() const {
  return subscription_id;
}

//------------------------------------------------------------------------------
void flexcn_subscription::set_notification_uri(
    const std::string& notification_uri) {
  nf_status_notification_uri = notification_uri;
}

//------------------------------------------------------------------------------
void flexcn_subscription::get_notification_uri(
    std::string& notification_uri) const {
  notification_uri = nf_status_notification_uri;
}

//------------------------------------------------------------------------------
void flexcn_subscription::set_sub_condition(const subscription_condition_t& c) {
  sub_condition = c;
}

//------------------------------------------------------------------------------
void flexcn_subscription::get_sub_condition(subscription_condition_t& c) const {
  c = sub_condition;
}

//------------------------------------------------------------------------------
/*
subscription_condition_t flexcn_subscription::get_sub_condition() const {
  return sub_condition;
}
*/

//------------------------------------------------------------------------------
void flexcn_subscription::set_notif_events(const std::vector<uint8_t>& ev_types) {
  notif_events = ev_types;
}

//------------------------------------------------------------------------------
void flexcn_subscription::add_notif_event(const uint8_t& ev_type) {
  notif_events.push_back(ev_type);
}

//------------------------------------------------------------------------------
void flexcn_subscription::get_notif_events(std::vector<uint8_t>& ev_types) const {
  ev_types = notif_events;
}

//------------------------------------------------------------------------------
std::vector<uint8_t> flexcn_subscription::get_notif_events() const {
  return notif_events;
}

//------------------------------------------------------------------------------
void flexcn_subscription::set_validity_time(const boost::posix_time::ptime& t) {
  validity_time = t;
}

//------------------------------------------------------------------------------
void flexcn_subscription::get_validity_time(boost::posix_time::ptime& t) const {
  t = validity_time;
}

//------------------------------------------------------------------------------
boost::posix_time::ptime flexcn_subscription::get_validity_time() const {
  return validity_time;
}

//------------------------------------------------------------------------------
void flexcn_subscription::display() {
  //TODO: handle later
}
