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

/*! \file flexcn_config.cpp
 \brief
 \author  Lionel GAUTHIER, Tien-Thinh NGUYEN
 \company Eurecom
 \date 2019
 \email: lionel.gauthier@eurecom.fr, tien-thinh.nguyen@eurecom.fr
 */

#include "flexcn_config.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "string.hpp"

// C includes
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "common_defs.h"
#include "if.hpp"
#include "logger.hpp"
#include "flexcn_app.hpp"

using namespace std;
using namespace libconfig;
using namespace oai::flexcn::app;

extern flexcn_config flexcn_cfg;

//------------------------------------------------------------------------------
int flexcn_config::load_interface(const Setting& if_cfg, interface_cfg_t& cfg) {
  if_cfg.lookupValue(FLEXCN_CONFIG_STRING_INTERFACE_NAME, cfg.if_name);

  util::trim(cfg.if_name);
  if (not boost::iequals(cfg.if_name, "none")) {
    std::string address = {};
    if_cfg.lookupValue(FLEXCN_CONFIG_STRING_IPV4_ADDRESS, address);
    util::trim(address);
    if (boost::iequals(address, "read")) {
      if (get_inet_addr_infos_from_iface(
              cfg.if_name, cfg.addr4, cfg.network4, cfg.mtu)) {
        Logger::flexcn_app().error(
            "Could not read %s network interface configuration", cfg.if_name);
        return RETURNerror;
      }
    } else {
      std::vector<std::string> words;
      boost::split(
          words, address, boost::is_any_of("/"), boost::token_compress_on);
      if (words.size() != 2) {
        Logger::flexcn_app().error(
            "Bad value " FLEXCN_CONFIG_STRING_IPV4_ADDRESS " = %s in config file",
            address.c_str());
        return RETURNerror;
      }
      unsigned char buf_in_addr[sizeof(struct in6_addr)];
      if (inet_pton(AF_INET, util::trim(words.at(0)).c_str(), buf_in_addr) ==
          1) {
        memcpy(&cfg.addr4, buf_in_addr, sizeof(struct in_addr));
      } else {
        Logger::flexcn_app().error(
            "In conversion: Bad value " FLEXCN_CONFIG_STRING_IPV4_ADDRESS
            " = %s in config file",
            util::trim(words.at(0)).c_str());
        return RETURNerror;
      }
      cfg.network4.s_addr = htons(
          ntohs(cfg.addr4.s_addr) &
          0xFFFFFFFF << (32 - std::stoi(util::trim(words.at(1)))));
    }
    if_cfg.lookupValue(FLEXCN_CONFIG_STRING_PORT, cfg.port);
  }
  return RETURNok;
}

int flexcn_config::load_nf_info(const Setting& if_cfg, nf_info_t& cfg) {
  if_cfg.lookupValue(FLEXCN_CONFIG_STRING_IPV4_ADDRESS, cfg.nf_addr_v4);
  if_cfg.lookupValue(FLEXCN_CONFIG_STRING_PORT, cfg.port);
  return RETURNok;
}

//------------------------------------------------------------------------------
int flexcn_config::load(const string& config_file) {
  Config cfg;
  unsigned char buf_in6_addr[sizeof(struct in6_addr)];

  // Read the file. If there is an error, report it and exit.
  try {
    cfg.readFile(config_file.c_str());
  } catch (const FileIOException& fioex) {
    Logger::flexcn_app().error(
        "I/O error while reading file %s - %s", config_file.c_str(),
        fioex.what());
    throw;
  } catch (const ParseException& pex) {
    Logger::flexcn_app().error(
        "Parse error at %s:%d - %s", pex.getFile(), pex.getLine(),
        pex.getError());
    throw;
  }

  const Setting& root = cfg.getRoot();

  try {
    const Setting& flexcn_cfg = root[FLEXCN_CONFIG_STRING_FLEXCN_CONFIG];
  } catch (const SettingNotFoundException& nfex) {
    Logger::flexcn_app().error("%s : %s", nfex.what(), nfex.getPath());
    return RETURNerror;
  }
  
  const Setting& flexcn_cfg = root[FLEXCN_CONFIG_STRING_FLEXCN_CONFIG];

  try {
    flexcn_cfg.lookupValue(FLEXCN_CONFIG_STRING_INSTANCE, instance);
  } catch (const SettingNotFoundException& nfex) {
    Logger::flexcn_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    flexcn_cfg.lookupValue(FLEXCN_CONFIG_STRING_PID_DIRECTORY, pid_dir);
  } catch (const SettingNotFoundException& nfex) {
    Logger::flexcn_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
  const Setting& amf_cfg = flexcn_cfg[FLEXCN_CONFIG_STRING_AMF];
  load_nf_info(amf_cfg, amf_info);

  } catch (const SettingNotFoundException& nfex) {
    Logger::flexcn_app().error("%s : %s", nfex.what(), nfex.getPath());
    return RETURNerror;
  }

  try {
    const Setting& smf_cfg = flexcn_cfg[FLEXCN_CONFIG_STRING_SMF];
    load_nf_info(smf_cfg, smf_info);

    } catch (const SettingNotFoundException& nfex) {
      Logger::flexcn_app().error("%s : %s", nfex.what(), nfex.getPath());
      return RETURNerror;
    }
  
  try {
    const Setting& sbi_cfg = flexcn_cfg[FLEXCN_CONFIG_STRING_INTERFACE_SBI];
    load_interface(sbi_cfg, sbi);

    // HTTP2 port
    if (!(sbi_cfg.lookupValue(
            FLEXCN_CONFIG_STRING_SBI_HTTP2_PORT, sbi_http2_port))) {
      Logger::flexcn_app().error(FLEXCN_CONFIG_STRING_SBI_HTTP2_PORT "failed");
      throw(FLEXCN_CONFIG_STRING_SBI_HTTP2_PORT "failed");
    }

    // SBI API VERSION
    if (!(sbi_cfg.lookupValue(
            FLEXCN_CONFIG_STRING_API_VERSION, sbi_api_version))) {
      Logger::flexcn_app().error(FLEXCN_CONFIG_STRING_API_VERSION "failed");
      throw(FLEXCN_CONFIG_STRING_API_VERSION "failed");
    }

  } catch (const SettingNotFoundException& nfex) {
    Logger::flexcn_app().error("%s : %s", nfex.what(), nfex.getPath());
    return RETURNerror;
  }
  


  return true;
}

//------------------------------------------------------------------------------
void flexcn_config::display() {
  Logger::flexcn_app().info(
      "==== EURECOM %s v%s ====", PACKAGE_NAME, PACKAGE_VERSION);
  Logger::flexcn_app().info("Configuration FLEXCN:");
  Logger::flexcn_app().info("- Instance ..............: %d\n", instance);
  Logger::flexcn_app().info("- PID dir ...............: %s\n", pid_dir.c_str());

  Logger::flexcn_app().info("- SBI Interface:");
  Logger::flexcn_app().info("    Interface name ......: %s", sbi.if_name.c_str());
  Logger::flexcn_app().info("    IPv4 Addr ...........: %s", inet_ntoa(sbi.addr4));
  Logger::flexcn_app().info("    Port ................: %d", sbi.port);
  Logger::flexcn_app().info("    HTTP2 port ..........: %d", sbi_http2_port);
  Logger::flexcn_app().info(
      "    API version..........: %s", sbi_api_version.c_str());
}

//------------------------------------------------------------------------------
flexcn_config::~flexcn_config() {}
