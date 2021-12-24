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

/*! \file flexcn_client.hpp
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_CLIENT_HPP_SEEN
#define FILE_FLEXCN_CLIENT_HPP_SEEN

#include <map>
#include <thread>

#include <curl/curl.h>
#include "flexcn_profile.hpp"

#include "comm_ops.hpp"

namespace oai {
namespace flexcn {
namespace app {

class flexcn_client {
 private:
  CURLM* curl_multi;
  std::vector<CURL*> handles;
  struct curl_slist* headers;
  flexcn_event& m_event_sub;
  bs2::connection
      task_connection;  // connection for performing curl_multi every 1ms

 public:
  flexcn_client(flexcn_event& ev);
  virtual ~flexcn_client();

  flexcn_client(flexcn_client const&) = delete;
  void operator=(flexcn_client const&) = delete;

  /*
   * Send Notification for the associated event to the subscribers
   * @param [const std::shared_ptr<flexcn_profile> &] profile: NF profile
   * @param [const uint8_t &] event_type: notification type
   * @param [const std::vector<std::string> &] uris: list of subscribed NFs' URI
   * @return void
   */
  void notify_subscribed_event(
      const std::shared_ptr<flexcn_profile>& profile, const uint8_t& event_type,
      const std::vector<std::string>& uris);

  /*
   * Create Curl handle for multi curl
   * @param [const std::string &] uri: URI of the subscribed NF
   * @param [std::string &] data: data to be sent
   * @param [std::string &] response_data: response data
   * @return pointer to the created curl
   */
  CURL* curl_create_handle(
      const std::string& uri, const std::string& data,
      std::string& response_data);

  /*
   * Prepare to send a request using curl multi
   * @param [const std::string &] uri: URI of the subscribed NF
   * @param [std::string &] data: data to be sent
   * @param [std::string &] response_data: response data
   * @return void
   */
  void send_curl_multi(
      const std::string& uri, const std::string& data,
      std::string& response_data);

  /*
   * Perform curl multi to actually process the available data
   * @param [uint64_t ms] ms: current time
   * @return void
   */
  void perform_curl_multi(uint64_t ms);

  /*
   * Finish all the curl transfers
   * @param void
   * @return void
   */
  void wait_curl_end();

  /*
   * Release all the handles
   * @param void
   * @return void
   */
  void curl_release_handles();

  /*
   * Subscribe to the task curl event
   * @param [uint64_t] ms: current time
   * @return void
   */
  void subscribe_task_curl();
};

bool subscribe_nf_event_exposure_service(
    std::shared_ptr<itti_n11_subscribe_pdu_session_status_notify> msg, const std::string& nf_name);

}  // namespace app
}  // namespace flexcn
}  // namespace oai
#endif /* FILE_FLEXCN_CLIENT_HPP_SEEN */
