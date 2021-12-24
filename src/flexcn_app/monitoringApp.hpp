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

/*! \file monitoringApp.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_MONITORING_APP_HPP_SEEN
#define FILE_MONITORING_APP_HPP_SEEN

#include <string>
#include "iApp.hpp"
#include "flexcn.h"

class MonitoringAppAPI : public iApp_api {
public:
   MonitoringAppAPI() : iApp_api() {};
   ~MonitoringAppAPI(){};
   virtual std::string name() const = 0;
   virtual int run() = 0;
   virtual nf_type_t get_type() const = 0;
   virtual std::string get_notif_ref() const = 0;

   virtual int subcribe_to_nf() = 0;
   virtual int unsubcribe_to_nf() = 0;
   // this signature is a subject to change
   // virtual int handle_xapp_request(const std::string& msg) = 0;
   
   // southbound handle
   virtual bool persist_data(const std::string& data, const std::string& id_str, int id_number) = 0;
   virtual std::string retrieve_all_data() = 0;
   virtual std::string retrieve_data_by_id(int id) = 0;
   virtual std::string retrieve_data_by_key(const std::string& id_str) = 0;
   virtual bool delete_by_id(int id) = 0;
   virtual bool delete_by_key(const std::string& id_str) = 0; 
   virtual bool delete_all() = 0; 
   
   virtual bool set_attribute(std::string attribute, std::string value, std::string type){};
   // put msg inside this plugin
   virtual bool put_msg(std::string msg){};
   
};

#endif