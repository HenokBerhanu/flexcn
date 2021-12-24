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

/*! \file flexcn_event_sig.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_EVENT_SIG_HPP_SEEN
#define FILE_FLEXCN_EVENT_SIG_HPP_SEEN

#include <boost/signals2.hpp>

namespace bs2 = boost::signals2;

namespace oai {
namespace flexcn {
namespace app {

// Reserved for later use 
    typedef bs2::signal_type<
        void(uint64_t), bs2::keywords::mutex_type<bs2::dummy_mutex>>::type
        task_sig_t;


}  // namespace app
}  // namespace flexcn
}  // namespace oai

#endif /* FILE_FLEXCN_EVENT_SIG_HPP_SEEN */
