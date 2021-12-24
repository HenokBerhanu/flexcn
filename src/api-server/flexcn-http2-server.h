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

/*! \file flexcn-http2-server.h
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_HTTP2_SERVER_SEEN
#define FILE_FLEXCN_HTTP2_SERVER_SEEN

#include "flexcn_app.hpp"
#include <nghttp2/asio_http2_server.h>
#include "SmContextUpdateMessage.h"
#include "SmContextMessage.h"
#include "SmContextReleaseMessage.h"
#include "uint_generator.hpp"
#include "flexcn.h"

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;
using namespace oai::flexcn_server::model;
using namespace oai::flexcn;

class flexcn_http2_server {
 public:
  flexcn_http2_server(std::string addr, uint32_t port,flexcn_app* flexcn_app_inst)
      : m_address(addr), m_port(port), server(), m_flexcn_app(flexcn_app_inst) {}
  void start();
  void init(size_t thr) {}
  void create_sm_contexts_handler(
      const SmContextMessage& smContextMessage, const response& response);
  void update_sm_context_handler(
      const std::string& flexcn_ref,
      const SmContextUpdateMessage& smContextUpdateMessage,
      const response& response);

  void release_sm_context_handler(
      const std::string& flexcn_ref,
      const SmContextReleaseMessage& smContextReleaseMessage,
      const response& response);
  void stop();

 private:
  util::uint_generator<uint32_t> m_promise_id_generator;
  std::string m_address;
  uint32_t m_port;
  http2 server;
  flexcn_app* m_flexcn_app;

 protected:
  static uint64_t generate_promise_id() {
    return util::uint_uid_generator<uint64_t>::get_instance().get_uid();
  }
};

#endif
