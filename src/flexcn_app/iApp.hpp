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

/*! \file iApp.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_IAPP_HPP_SEEN
#define FILE_IAPP_HPP_SEEN

#include <string>
#include <nlohmann/json.hpp>
#include "flexcn.h"

class iApp_api {
public:
   iApp_api() {};
   ~iApp_api() {};
   virtual std::string name() const = 0;
   virtual int run() = 0;
   virtual bool set_attribute(std::string attribute, std::string value, std::string type){};
   // put msg inside this plugin
   virtual bool put_msg(std::string msg){};
   virtual nf_type_t get_type() const = 0; 
};

#endif