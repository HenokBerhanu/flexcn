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

/*! \file flexcn_config.hpp
 * \brief
 \author  Lionel GAUTHIER, Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: lionel.gauthier@eurecom.fr, tien-thinh.nguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_CONFIG_HPP_SEEN
#define FILE_FLEXCN_CONFIG_HPP_SEEN

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <libconfig.h++>

#include <mutex>
#include <vector>

#define FLEXCN_CONFIG_STRING_FLEXCN_CONFIG "FLEXCN"
#define FLEXCN_CONFIG_STRING_PID_DIRECTORY "PID_DIRECTORY"
#define FLEXCN_CONFIG_STRING_INSTANCE "INSTANCE"
#define FLEXCN_CONFIG_STRING_AMF "AMF"
#define FLEXCN_CONFIG_STRING_SMF "SMF"
#define FLEXCN_CONFIG_STRING_INTERFACE_SBI "SBI_INTERFACE"
#define FLEXCN_CONFIG_STRING_INTERFACE_NAME "INTERFACE_NAME"
#define FLEXCN_CONFIG_STRING_IPV4_ADDRESS "IPV4_ADDRESS"
#define FLEXCN_CONFIG_STRING_PORT "PORT"
#define FLEXCN_CONFIG_STRING_SBI_HTTP2_PORT "HTTP2_PORT"
#define FLEXCN_CONFIG_STRING_API_VERSION "API_VERSION"

// custom define for flexcn
#define FLEXCN_CONFIG_STRING_CN_VERSION "CORE_NETWORK_VERSION"

namespace oai {
namespace flexcn {
namespace app {

typedef struct interface_cfg_s {
  std::string if_name;
  struct in_addr addr4;
  struct in_addr network4;
  struct in6_addr addr6;
  unsigned int mtu;
  unsigned int port;
} interface_cfg_t;

typedef struct nf_info_s {
  std::string nf_addr_v4;
  unsigned int port;
} nf_info_t;

class flexcn_config {
 private:
  int load_interface(const libconfig::Setting& if_cfg, interface_cfg_t& cfg);
  int load_nf_info(const libconfig::Setting& if_cfg, nf_info_t& cfg);

 public:
  // member for conf of flexcn
  unsigned int core_network_version = 5;

  /* Reader/writer lock for this configuration */
  std::mutex m_rw_lock;
  std::string pid_dir;
  unsigned int instance = 0;

  interface_cfg_t sbi;
  nf_info_t amf_info;
  nf_info_t smf_info;

  unsigned int sbi_http2_port;
  std::string sbi_api_version;
  // Local configuration
  bool local_configuration = false;

  flexcn_config() : m_rw_lock(), pid_dir(), instance(0), sbi() {
    sbi.port        = 80;
    sbi_http2_port  = 8080;
    sbi_api_version = "v1";
  };
  virtual ~flexcn_config();
  void lock() { m_rw_lock.lock(); };
  void unlock() { m_rw_lock.unlock(); };
  int load(const std::string& config_file);
  void display();
};

}  // namespace app
}  // namespace flexcn
}  // namespace oai

#endif /* FILE_FLEXCN_CONFIG_HPP_SEEN */
