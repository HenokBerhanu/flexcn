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

/*! \file cassandra_5g_db.hpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#ifndef FILE_CASSANDRA_5G_DB_HPP_SEEN
#define FILE_CASSANDRA_5G_DB_HPP_SEEN

#include <cassandra.h>
#include <string>
#include "database_5g_wrapper.hpp"

using namespace oai::flexcn_server::model;

class Cassandra5GDB : public Database5GWrapper {

private:
  /* Setup and connect to cluster */
  CassCluster* m_cluster;
  CassSession* m_session;
  CassFuture* m_connect_future;
  std::string m_database_IP;
  const CassPrepared* m_insert_5g_prepared;
  /* The prepared object can now be used to create statements that can be executed */
  CassStatement* m_insert_5g_statement;

  std::string m_space;
  std::string m_table_5g_context;

  CassError query(std::string str_query);
  void setup_insert_query();
  void create_space_and_table(std::string space_name, std::string table_name);
  std::vector<SMFData> select_query(std::string str_query);
  SMFData get_a_smf_data_from_a_cass_row(const CassRow* row);
  std::vector<SMFData> get_smf_data_from_cass_result(const CassResult* result);

public:
    Cassandra5GDB(const std::string& database_ip);
    ~Cassandra5GDB();

    bool insert_5g_context(const SMFData& bearer,const std::string& ids, int id);
    bool delete_by_internal_id(int id);
    bool delete_by_imsi_bearer_id(std::string imsi, int bearerID);
    bool delete_all();
    std::vector<SMFData> get_all_rows();
    std::vector<SMFData> get_row_by_id(int id);
    std::vector<SMFData> get_row_by_imsi_bearer_id(std::string imsi, int bearerID);

};

#endif