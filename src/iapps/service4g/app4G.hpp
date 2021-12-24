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

/*! \file app4G.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_APP4G_HPP_SEEN
#define FILE_APP4G_HPP_SEEN

#include <memory>
#include <string>
#include <vector>
#include "Bearer.h"
#include "database_wrapper.hpp"


class App4G {
    private:
        std::shared_ptr<DatabaseWrapper> m_database_wrapper;
        // next available id
        unsigned int m_4gid;
    
    public: 
        App4G(const std::string& addr);
        ~App4G();
        // 4G operation
        bool add_bearer(Bearer &bearer);
        bool delete_a_single_bearer_by_imsi_bearer(const std::string &imsiBearer);
        bool delete_a_single_bearer_by_id(const std::string &id);
        bool delete_all_bearers();
        std::vector<Bearer> get_stats();
        std::vector<Bearer> get_stats_by_imsi_bearer(const std::string &imsiBearer);
        std::vector<Bearer> get_stats_by_id(const std::string &id);

};

#endif