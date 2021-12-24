/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 *file except in compliance with the License. You may obtain a copy of the
 *License at
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

/*! \file flexcn_event.hpp
 \brief
 \author
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_EVENT_HPP_SEEN
#define FILE_FLEXCN_EVENT_HPP_SEEN

#include <boost/signals2.hpp>
namespace bs2 = boost::signals2;

#include "flexcn.h"
#include "flexcn_event_sig.hpp"
#include "task_manager.hpp"

namespace oai {
namespace flexcn {
namespace app {

class task_manager;
// class flexcn_profile;

class flexcn_event {
 public:
  flexcn_event(){};
  flexcn_event(flexcn_event const&) = delete;
  void operator=(flexcn_event const&) = delete;

  static flexcn_event& get_instance() {
    static flexcn_event instance;
    return instance;
  }

  // class register/handle event
  friend class flexcn_app;
  friend class task_manager;
  friend class flexcn_profile;

  // reserved for later
    /*
   * Subscribe to the task tick event
   * @param [const task_sig_t::slot_type &] sig
   * @param [uint64_t] period: interval between two events
   * @param [uint64_t] start:
   * @return void
   */
  bs2::connection subscribe_task_tick(
      const task_sig_t::slot_type& sig, uint64_t period, uint64_t start = 0);

  /*
   * Subscribe to the extended task tick event
   * @param [const task_sig_t::slot_type &] sig
   * @param [uint64_t] period: interval between two events
   * @param [uint64_t] start:
   * @return void
   */
  bs2::connection subscribe_task_tick_extended(
      const task_sig_t::extended_slot_type& sig, uint64_t period,
      uint64_t start = 0);


  private:
  task_sig_t task_tick;


};
}  // namespace app
}  // namespace flexcn
}  // namespace oai

#endif /* FILE_FLEXCN_EVENT_HPP_SEEN */
