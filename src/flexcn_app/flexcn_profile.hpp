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

/*! \file flexcn_profile.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_PROFILE_HPP_SEEN
#define FILE_FLEXCN_PROFILE_HPP_SEEN

#include <arpa/inet.h>
#include <netinet/in.h>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <shared_mutex>
#include <utility>
#include <vector>

#include "logger.hpp"
#include "flexcn.h"
#include "flexcn_event.hpp"

namespace oai {
namespace flexcn {
namespace app {

using namespace std;

class flexcn_profile : public std::enable_shared_from_this<flexcn_profile> {
 public:
  flexcn_profile(flexcn_event& ev)
      : m_event_sub(ev),
        nf_type(NF_TYPE_UNKNOWN),
        heartBeat_timer(0),
        heartbeart_mutex() {
    nf_instance_name = "";
    nf_status        = "";
    first_update     = true;
    is_updated       = false;
  }
  flexcn_profile(flexcn_event& ev, const nf_type_t type)
      : m_event_sub(ev),
        nf_type(type),
        heartBeat_timer(0),
        heartbeart_mutex() {
    nf_instance_name = "";
    nf_status        = "";
    first_update     = true;
    is_updated       = false;
  }

  flexcn_profile(flexcn_event& ev, const std::string& id)
      : m_event_sub(ev),
        nf_instance_id(id),
        heartBeat_timer(0),
        nf_type(NF_TYPE_UNKNOWN),
        heartbeart_mutex() {
    nf_instance_name = "";
    nf_status        = "";
    first_update     = true;
    is_updated       = false;
  }

  flexcn_profile(flexcn_profile& b) = delete;

  virtual ~flexcn_profile() {
    Logger::flexcn_app().debug("Delete FLEXCN Profile instance...");
    if (task_connection.connected()) task_connection.disconnect();
    if (first_hb_connection.connected()) first_hb_connection.disconnect();
  }

  /*
   * Set NF instance ID
   * @param [const std::string &] instance_id: instance id
   * @return void
   */
  void set_nf_instance_id(const std::string& instance_id);

  /*
   * Get NF instance ID
   * @param [std::string &] instance_id: store instance id
   * @return void:
   */
  void get_nf_instance_id(std::string& instance_id) const;

  /*
   * Get NF instance ID
   * @param [std::string &] instance_id: store instance id
   * @return void:
   */
  std::string get_nf_instance_id() const;

  /*
   * Set NF instance name
   * @param [const std::string &] instance_name: instance name
   * @return void
   */
  void set_nf_instance_name(const std::string& instance_name);

  /*
   * Get NF instance ID
   * @param [std::string &] instance_name: store instance name
   * @return void:
   */
  void get_nf_instance_name(std::string& instance_name) const;

  /*
   * Get NF instance name
   * @param
   * @return [std::string] instance name
   */
  std::string get_nf_instance_name() const;

  /*
   * Set NF instance status
   * @param [const std::string &] status: instance status
   * @return void
   */
  void set_nf_status(const std::string& status);

  /*
   * Get NF instance status
   * @param [std::string &] status: store instance status
   * @return void:
   */
  void get_nf_status(std::string& status) const;

  /*
   * Get NF status
   * @param
   * @return [std::string] instance status
   */
  std::string get_nf_status() const;

  /*
   * Get NF type
   * @param
   * @return [std::string] nf type
   */
  nf_type_t get_nf_type() const;

  /*
   * Set NF type
   * @param [const nf_type_t &] type: nf type
   * @return void
   */
  void set_nf_type(const nf_type_t& type);

  /*
   * Set NF instance heartBeat_timer
   * @param [const std::string &] timer: heartBeat_timer
   * @return void
   */
  void set_nf_heartBeat_timer(const int32_t& timer);

  /*
   * Get NF instance heartBeat_timer
   * @param [std::string &] timer: store heartBeat_timer
   * @return void:
   */
  void get_nf_heartBeat_timer(int32_t& timer) const;

  /*
   * Get NF heartBeat_timer
   * @param void
   * @return heartBeat_timer
   */
  int32_t get_nf_heartBeat_timer() const;


  /*
   * Print related-information for NF profile
   * @param void
   * @return void:
   */
  virtual void display();

  /*
   * Update a new value for a member of NF profile
   * @param [const std::string &] path: member name
   * @param [const std::string &] value: new value
   * @return true if success, otherwise false
   */
  virtual bool replace_profile_info(
      const std::string& path, const std::string& value);

  /*
   * Add a new value for a member of NF profile
   * @param [const std::string &] path: member name
   * @param [const std::string &] value: new value
   * @return true if success, otherwise false
   */
  virtual bool add_profile_info(
      const std::string& path, const std::string& value);

  /*
   * Remove value of a member of NF profile
   * @param [const std::string &] path: member name
   * @param [const std::string &] value: new value
   * @return true if success, otherwise false
   */
  virtual bool remove_profile_info(const std::string& path);

  /*
   * Represent NF profile as json object
   * @param [nlohmann::json &] data: Json data
   * @return void
   */
  virtual void to_json(nlohmann::json& data) const;

  /*
   * Subscribe to the HBT timeout event (after receiving NF Update)
   * @param [uint64_t] ms: current time
   * @return void
   */
  void subscribe_heartbeat_timeout_nfupdate(uint64_t ms);

  /*
   * Subscribe to the HBT timeout event (after receiving NF Registration)
   * @param [uint64_t] ms: current time
   * @return void
   */
  void subscribe_heartbeat_timeout_nfregistration(uint64_t ms);

  /*
   * Handle heartbeart timeout event
   * @param [uint64_t] ms: current time
   * @return void
   */
  void handle_heartbeart_timeout(uint64_t ms);

  /*
   * Handle heartbeart timeout event after NF Registration
   * @param [uint64_t] ms: current time
   * @return void
   */
  void handle_heartbeart_timeout_nfregistration(uint64_t ms);

  /*
   * Handle heartbeart timeout event after NF Update
   * @param [uint64_t] ms: current time
   * @return void
   */
  void handle_heartbeart_timeout_nfupdate(uint64_t ms);

  /*
   * Unubscribe to HBT event (after NF Registration)
   * @param void
   * @return void
   */
  bool unsubscribe_heartbeat_timeout_nfregistration();

  /*
   * Unubscribe to HBT event (after NF Update)
   * @param void
   * @return void
   */
  bool unsubscribe_heartbeat_timeout_nfupdate();

  /*
   * Set status updated to true
   * @param void
   * @return void
   */
  void set_status_updated(bool status);

 protected:
  flexcn_event& m_event_sub;
  bs2::connection
      task_connection;  // connection for the HBT timeout (after NF Update)
  bs2::connection first_hb_connection;  // connection for first HBT timeout
                                        // (after NF Registration)
  bool first_update;
  bool is_updated;
  mutable std::shared_mutex heartbeart_mutex;

  std::string nf_instance_id;
  std::string nf_instance_name;
  nf_type_t nf_type;
  std::string nf_status;
  int32_t heartBeat_timer;
};

}  // namespace app
}  // namespace flexcn
}  // namespace oai

#endif
