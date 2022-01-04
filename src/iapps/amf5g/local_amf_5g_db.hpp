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

/*! \file local_amf_5g_db.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_LOCAL_AMF_5G_DB_HPP_SEEN
#define FILE_LOCAL_AMF_5G_DB_HPP_SEEN

#include <string>
#include <map>
#include "database_amf_5g_wrapper.hpp"


class Local5GAMFDB : public Database5GAMFWrapper {
private:
  //5g data
  std::map<
      std::string,  // ueid
      std::map<int,AMFData>>  m_main_database_5g;

public:
    Local5GAMFDB(const std::string& database_ip);
    ~Local5GAMFDB();

    bool insert_5g_context(const AMFData& bearer, const std::string& ids, int id);
    bool delete_by_internal_id(int id);
    bool delete_by_key(std::string supi, int bearerID = 0);
    bool delete_all();
    std::vector<AMFData> get_all_rows();
    std::vector<AMFData> get_row_by_id(int id);
    std::vector<AMFData> get_row_by_key(std::string key, int extraID=0);
};

#endif