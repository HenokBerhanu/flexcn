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

/*! \file amf_app.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_AMF_APP_HPP_SEEN
#define FILE_AMF_APP_HPP_SEEN

#include <string>
#include <nlohmann/json.hpp>

#include "monitoringApp.hpp"
#include "database_amf_5g_wrapper.hpp"
#include "flexcn.h"

#define NRF_CURL_TIMEOUT_MS 100L

class AMFApp : public MonitoringAppAPI {
public:
   AMFApp(const std::string& flexcn_ip, int flexcn_port,
            const std::string& amf_ip, int amf_port);
   ~AMFApp(){};
   std::string name() const {
       return "AMF App Handler";
   };
    
    bool set_attribute(std::string attribute, std::string value, std::string type){};
    int subcribe_to_nf();
    int unsubcribe_to_nf(){
        //TODO:
    };
    std::string get_notif_ref() const {
        return "amf001";
    };
    nf_type_t get_type() const {
        return nf_type_t::NF_TYPE_AMF;
    }

    bool persist_data(const std::string& data, const std::string& id_str, int id_number);
    std::string retrieve_data_by_id(int id);
    std::string retrieve_data_by_key(const std::string& id_str);
    //return data in json string format 
    std::string retrieve_all_data();
    
    bool delete_by_id(int id) {
        // not supported
        return false;
    };
    
    bool delete_by_key(const std::string& id_str) {
        // not supported
        return false;
    }; 
    
    bool delete_all() {
        // not supported
        return false;
    }; 

    int run(){
        return 0;
    };

    nf_type_t get_type() {
        return nf_type_t::NF_TYPE_AMF;
    }

private:
    std::shared_ptr<Database5GAMFWrapper> m_database_wrapper;
    std::string m_flexcn_ip, m_amf_ip;
    int m_flexcn_port, m_amf_port;
    unsigned int m_data_index = 0;  
};

#endif