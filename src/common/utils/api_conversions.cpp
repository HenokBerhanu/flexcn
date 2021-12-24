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

/*! \file api_conversions.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <nlohmann/json.hpp>
#include <regex>

#include "api_conversions.hpp"
#include "logger.hpp"
#include "flexcn.h"
#include "string.hpp"

using namespace oai::flexcn_server::model;
using namespace oai::flexcn::app;
using namespace oai::flexcn;

//------------------------------------------------------------------------------
nf_type_t api_conv::string_to_nf_type(const std::string& str) {
  if (str.compare("NRF") == 0) return NF_TYPE_NRF;
  if (str.compare("AMF") == 0) return NF_TYPE_AMF;
  if (str.compare("SMF") == 0) return NF_TYPE_SMF;
  if (str.compare("AUSF") == 0) return NF_TYPE_AUSF;
  if (str.compare("NEF") == 0) return NF_TYPE_NEF;
  if (str.compare("PCP") == 0) return NF_TYPE_PCF;
  if (str.compare("SMSF") == 0) return NF_TYPE_SMSF;
  if (str.compare("NSSF") == 0) return NF_TYPE_NSSF;
  if (str.compare("UDR") == 0) return NF_TYPE_UDR;
  if (str.compare("LMF") == 0) return NF_TYPE_LMF;
  if (str.compare("GMLC") == 0) return NF_TYPE_GMLC;
  if (str.compare("5G_EIR") == 0) return NF_TYPE_5G_EIR;
  if (str.compare("SEPP") == 0) return NF_TYPE_SEPP;
  if (str.compare("UPF") == 0) return NF_TYPE_UPF;
  if (str.compare("N3IWF") == 0) return NF_TYPE_N3IWF;
  if (str.compare("AF") == 0) return NF_TYPE_AF;
  if (str.compare("UDSF") == 0) return NF_TYPE_UDSF;
  if (str.compare("BSF") == 0) return NF_TYPE_BSF;
  if (str.compare("CHF") == 0) return NF_TYPE_CHF;
  if (str.compare("NWDAF") == 0) return NF_TYPE_NWDAF;
  // default
  return NF_TYPE_UNKNOWN;
}

//------------------------------------------------------------------------------
patch_op_type_t api_conv::string_to_patch_operation(const std::string& str) {
  if (str.compare("add") == 0) return PATCH_OP_ADD;
  if (str.compare("copy") == 0) return PATCH_OP_COPY;
  if (str.compare("move") == 0) return PATCH_OP_MOVE;
  if (str.compare("remove") == 0) return PATCH_OP_REMOVE;
  if (str.compare("replace") == 0) return PATCH_OP_REPLACE;
  if (str.compare("test") == 0) return PATCH_OP_TEST;
  // default
  return PATCH_OP_UNKNOWN;
}

bool api_conv::validate_uuid(const std::string& str) {
  // should be verified with Capital letter
  static const std::regex e(
      "[a-f0-9]{8}-[a-f0-9]{4}-[0-5][a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{"
      "12}");
  return regex_match(str, e);
}
