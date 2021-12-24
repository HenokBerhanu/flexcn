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

/*! \file flexcn_subscription.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_SUBSCRIPTION_HPP_SEEN
#define FILE_FLEXCN_SUBSCRIPTION_HPP_SEEN

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include "logger.hpp"
#include "flexcn_event.hpp"
#include "flexcn_profile.hpp"

namespace oai {
namespace flexcn {
namespace app {
using namespace std;

typedef struct subscription_condition_s {

} subscription_condition_t;

class flexcn_subscription {
 public:
  flexcn_subscription(flexcn_event& ev) : m_event_sub(ev) {
    validity_time = boost::posix_time::from_iso_string("20991231T235959Z");
  };

  flexcn_subscription(flexcn_subscription const&) = delete;

  virtual ~flexcn_subscription() {
    Logger::flexcn_app().debug("Delete FLEXCN Subscription instance...");
    if (ev_connection.connected()) ev_connection.disconnect();
  }

  void operator=(flexcn_subscription const&) = delete;

  /*
   * Set the subscription id
   * @param [const std::string &]: sub_id: Subscription id
   * @return void
   */
  void set_subscription_id(const std::string& sub_id);

  /*
   * Get the subscription id
   * @param [std::string &]: sub_id: Subscription id
   * @return void
   */
  void get_subscription_id(std::string& sub_id) const;

  /*
   * Get the subscription id
   * @param [void]
   * @return subscription id
   */
  std::string get_subscription_id() const;

  /*
   * Set the notification URI (URI where the notification will be sent to)
   * @param [const std::string &]: notification_uri: Notification URI
   * @return void
   */
  void set_notification_uri(const std::string& notification_uri);

  /*
   * Get the notification URI (URI where the notification will be sent to)
   * @param [std::string &]: notification_uri: Notification URI
   * @return void
   */
  void get_notification_uri(std::string& notification_uri) const;

  /*
   * Set the subscription condition
   * @param [const subscription_condition_t &]: c: Subscription condition
   * @return void
   */
  void set_sub_condition(const subscription_condition_t& c);

  /*
   * Get the subscription condition
   * @param [const subscription_condition_t &]: c: Subscription condition
   * @return void
   */
  void get_sub_condition(subscription_condition_t& c) const;
  // subscription_condition_t get_sub_condition() const;

  /*
   * Set the notification events
   * @param [const std::vector<uint8_t> &]: ev_types: Array of the notification
   * event types
   * @return void
   */
  void set_notif_events(const std::vector<uint8_t>& ev_types);

  /*
   * Add a notification type to the list of notification events
   * @param [const uint8_t &]: ev_type: A notification type
   * @return void
   */
  void add_notif_event(const uint8_t& ev_type);

  /*
   * Get the notification events
   * @param [std::vector<uint8_t> &]: ev_types: Array of the notification event
   * types
   * @return void
   */
  void get_notif_events(std::vector<uint8_t>& ev_types) const;

  /*
   * Get the notification events
   * @param [void]
   * @return Array of the notification event types
   */
  std::vector<uint8_t> get_notif_events() const;

  /*
   * Set the validity time
   * @param [const boost::posix_time::ptime &]t:  validity time
   * @return
   */
  void set_validity_time(const boost::posix_time::ptime& t);

  /*
   * Get the validity time
   * @param [boost::posix_time::ptime &]t:  validity time
   * @return
   */
  void get_validity_time(boost::posix_time::ptime& t) const;

  /*
   * Get the validity time
   * @param [void]
   * @return [boost::posix_time::ptime &] validity time
   */
  boost::posix_time::ptime get_validity_time() const;


  /*
   * Display all the members of a subscription
   * @param [void]
   * @return void
   */
  void display();

 private:
  std::string nf_status_notification_uri;
  std::string subscription_id;
  subscription_condition_t sub_condition;
  std::vector<uint8_t> notif_events;
  flexcn_event& m_event_sub;
  bs2::connection ev_connection;
  boost::posix_time::ptime validity_time;
};
}  // namespace app
}  // namespace flexcn
}  // namespace oai

#endif /* FILE_FLEXCN_SUBSCRIPTION_HPP_SEEN */
