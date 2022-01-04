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

/*! \file local_db.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_LOCAL_DB_HPP_SEEN
#define FILE_LOCAL_DB_HPP_SEEN

#include <string>
#include "database_wrapper.hpp"
#include "Bearer.h"

using namespace oai::flexcn_server::model;

class Local4GDB : public DatabaseWrapper {

private:
  //4g data
  std::map<unsigned int, Bearer> m_main_database_4g; 
  std::map<std::string, std::map<unsigned int, unsigned int>> m_imsi_bearer_id_to_main_id;

public:
    Local4GDB(const std::string& database_ip);
    ~Local4GDB();

    bool insert_4g_context(const Bearer& bearer, int id); 
    bool delete_by_internal_id(int id);
    bool delete_by_imsi_bearer_id(std::string imsi, int bearerID);
    bool delete_all();
    std::vector<Bearer> get_all_rows();
    std::vector<Bearer> get_row_by_id(int id);
    std::vector<Bearer> get_row_by_imsi_bearer_id(std::string imsi, int bearerID);

};

#endif