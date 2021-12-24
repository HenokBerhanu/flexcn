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

/*! \file flexcn_app.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_APP_HPP_SEEN
#define FILE_FLEXCN_APP_HPP_SEEN

#include <string>
#include "NFProfile.h"
#include "PatchItem.h"
#include "ProblemDetails.h"
#include "flexcn_event.hpp"
#include "flexcn_profile.hpp"
#include "flexcn_subscription.hpp"
#include "uint_generator.hpp"

namespace oai {
namespace flexcn {
namespace app {

// using namespace oai::flexcn::model;
class flexcn_config;
class flexcn_app {
 public:
  explicit flexcn_app(const std::string& config_file, flexcn_event& ev, int cn_version);
  flexcn_app(flexcn_app const&) = delete;
  void operator=(flexcn_app const&) = delete;

  virtual ~flexcn_app();

  /*
   * Generate a random UUID for FLEXCN instance
   * @param [void]
   * @return void
   */
  void generate_uuid();

  /*
   * Subscribe to the task tick event
   * @param [uint64_t &] ms: Current time in ms
   * @return void
   */
  void subscribe_task_tick(uint64_t ms);

  /*
   * Handle when hearbeart timer expires
   * @param [uint64_t] ms: current time in milliseconds
   * @return void
   */
  void handle_heartbeart_timeout(uint64_t ms);

  /*
   * Generate an unique ID for the new subscription
   * @param [const std::string &] sub_id: the generated ID
   * @return void
   */
  void generate_ev_subscription_id(std::string& sub_id);

  /*
   * Generate an unique ID for the new subscription
   * @param void
   * @return the generated ID
   */
  evsub_id_t generate_ev_subscription_id();

  /*
   * Get the list of subscriptions to the profile with notification type
   * @param [const std::string &] profile_id: Profile ID of the NF
   * @param [const uint8_t &] notification_type: requested notification type
   * @param [std::vector<std::string> &] uris: vector stores list of uri of
   * subscribed NFs
   * @return void
   */
  void get_subscription_list(
      const std::string& profile_id, const uint8_t& notification_type,
      std::vector<std::string>& uris) const;


 private:
  std::string flexcn_instance_id;  // FLEXCN instance id

  std::map<std::string, std::shared_ptr<flexcn_subscription>>
      subscrition_id2flexcn_subscription;
  mutable std::shared_mutex m_subscription_id2flexcn_subscription;
  flexcn_event& m_event_sub;
  util::uint_generator<uint32_t> evsub_id_generator;
  std::vector<bs2::connection> connections;

};
}  // namespace app
}  // namespace flexcn
}  // namespace oai
#include "flexcn_config.hpp"

#endif /* FILE_FLEXCN_APP_HPP_SEEN */
