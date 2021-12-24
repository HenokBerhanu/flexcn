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

/*! \file flexcn-http2-server.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include "flexcn-http2-server.h"
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <nlohmann/json.hpp>

#include "logger.hpp"
#include "mime_parser.hpp"
#include "3gpp_29.500.h"
#include "flexcn_config.hpp"
#include "flexcn.h"

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;
using namespace oai::flexcn_server::model;

//------------------------------------------------------------------------------
void flexcn_http2_server::start() {
}

//------------------------------------------------------------------------------
void flexcn_http2_server::create_sm_contexts_handler(
    const SmContextMessage& smContextMessage, const response& response) {
  }

//------------------------------------------------------------------------------
void flexcn_http2_server::update_sm_context_handler(
    const std::string& flexcn_ref,
    const SmContextUpdateMessage& smContextUpdateMessage,
    const response& response) {
}

//------------------------------------------------------------------------------
void flexcn_http2_server::release_sm_context_handler(
    const std::string& flexcn_ref,
    const SmContextReleaseMessage& smContextReleaseMessage,
    const response& response) {
}

//------------------------------------------------------------------------------
void flexcn_http2_server::stop() {
  server.stop();
}
