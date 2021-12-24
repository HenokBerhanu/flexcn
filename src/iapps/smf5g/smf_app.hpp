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

/*! \file smf_app.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_SMF_APP_HPP_SEEN
#define FILE_SMF_APP_HPP_SEEN

#include <string>
#include <nlohmann/json.hpp>

#include "monitoringApp.hpp"
#include "database_5g_wrapper.hpp"

#include "flexcn.h"

using namespace oai::flexcn_server::model;

class SMFApp : public MonitoringAppAPI {
public:
   SMFApp(const std::string& flexcn_ip, int flexcn_port,
            const std::string& smf_ip, int smf_port);
   ~SMFApp(){};
   std::string name() const {
       return "SMF App Handler";
   };
    
    bool set_attribute(std::string attribute, std::string value, std::string type){};
    int subcribe_to_nf();
    int unsubcribe_to_nf() {
        // TODO
    };
    nf_type_t get_type() const {
        return nf_type_t::NF_TYPE_SMF;
    };

    std::string get_notif_ref() const {
        return "notifid01";
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

private:
    std::shared_ptr<Database5GWrapper> m_database_wrapper;
    std::string m_flexcn_ip, m_smf_ip;
    int m_flexcn_port, m_smf_port;

    // bool send_to_database(const SMFData& data);
 
};

#endif