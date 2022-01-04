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

/*! \file cassandra_5g_db.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include "cassandra_5g_db.hpp"
#include "logger.hpp"
#include <iostream>

Cassandra5GDB::Cassandra5GDB(const std::string& database_ip)
    : Database5GWrapper(database_ip) {
  /* Setup and connect to cluster */
  m_cluster = cass_cluster_new();
  m_session = cass_session_new();

  //
  m_database_IP      = database_ip;
  m_space            = "store";
  m_table_5g_context = "context_5G";

  /* Add contact points */
  cass_cluster_set_contact_points(m_cluster, m_database_IP.c_str());

  /* Provide the cluster object as configuration to connect the session */
  m_connect_future = cass_session_connect(m_session, m_cluster);

  /* This operation will block until the result is ready */
  CassError rc = cass_future_error_code(m_connect_future);

  printf("Connect result: %s\n", cass_error_desc(rc));

  create_space_and_table(m_space, m_table_5g_context);
  setup_insert_query();
}

Cassandra5GDB::~Cassandra5GDB() {
  /* Statement objects can be freed immediately after being executed */
  /* The prepared object must be freed */
  cass_prepared_free(m_insert_5g_prepared);
  cass_session_free(m_session);
  cass_cluster_free(m_cluster);
  cass_future_free(m_connect_future);
  // TODO: change to debug mode 
  std::cout << "Clean alll" << std::endl;
}

void Cassandra5GDB::setup_insert_query() {
  std::string str_insert_5g_query =
      "INSERT INTO " + m_space + "." + m_table_5g_context +
      " (row_id, extra_id, supi, data) VALUES (?, ?, ?, ?);";

  /* Prepare the statement on the Cassandra cluster */
  CassFuture* prepare_future =
      cass_session_prepare(m_session, str_insert_5g_query.c_str());

  /* Wait for the statement to prepare and get the result */
  CassError rc = cass_future_error_code(prepare_future);

  printf("Prepare result: %s\n", cass_error_desc(rc));

  if (rc != CASS_OK) {
    /* Handle error */
    cass_future_free(prepare_future);
    std::cout << "Failed to setting up the insert query" << std::endl;
    return;
  }

  /* Get the prepared object from the future */
  m_insert_5g_prepared = cass_future_get_prepared(prepare_future);

  /* The future can be freed immediately after getting the prepared object */
  cass_future_free(prepare_future);
  std::cout << "Success to setting up the insert query" << std::endl;
}

CassError Cassandra5GDB::query(std::string str_query) {
  // example of query / "INSERT INTO example (key, value) VALUES ('abc', 123)"

  /* Create a statement with zero parameters */
  CassStatement* statement = cass_statement_new(str_query.c_str(), 0);
  CassFuture* query_future = cass_session_execute(m_session, statement);

  /* Statement objects can be freed immediately after being executed */
  cass_statement_free(statement);

  /* This will block until the query has finished */
  CassError rc = cass_future_error_code(query_future);
  cass_future_free(query_future);
  return rc;
}

std::vector<SMFData> Cassandra5GDB::select_query(std::string str_query) {
  /* Build statement and execute query */
  CassStatement* statement = cass_statement_new(str_query.c_str(), 0);
  CassFuture* result_future = cass_session_execute(m_session, statement);

  std::vector<SMFData> v_b;
  if (cass_future_error_code(result_future) == CASS_OK) {
    /* Retrieve result set and iterate over the rows */
    const CassResult* result = cass_future_get_result(result_future);
    v_b                      = get_smf_data_from_cass_result(result);

    cass_result_free(result);

  } else {
    /* Handle error */
    const char* message_data;
    size_t message_length;

    cass_future_error_message(result_future, &message_data, &message_length);
    fprintf(
        stderr, "Unable to run query: '%.*s'\n", (int) message_length,
        message_data);
  }

  cass_statement_free(statement);
  cass_future_free(result_future);
  return v_b;
}

std::string get_string_from_cass_value(
    const CassRow* row, std::string name_col) {
  const CassValue* value = cass_row_get_column_by_name(row, name_col.c_str());
  const char* imsi;
  size_t output_size;
  CassError rc = cass_value_get_string(value, &imsi, &output_size);
  if (rc != CASS_OK) {
    std::cout << "Failed to get string value from columns" << std::endl;
    return nullptr;
  }
  return std::string(imsi, output_size);
}

SMFData make_smf_data_from_text(const std::string& data) {
  return SMFData(data);
}

SMFData Cassandra5GDB::get_a_smf_data_from_a_cass_row(const CassRow* row) {
  std::string data = get_string_from_cass_value(row, "data");
  return make_smf_data_from_text(data);
}

std::vector<SMFData> Cassandra5GDB::get_smf_data_from_cass_result(
    const CassResult* result) {
  std::vector<SMFData> v_bearers;
  CassIterator* rows = cass_iterator_from_result(result);

  while (cass_iterator_next(rows)) {
    const CassRow* row = cass_iterator_get_row(rows);
    SMFData br         = get_a_smf_data_from_a_cass_row(row);
    v_bearers.push_back(br);
  }
  cass_iterator_free(rows);
  return v_bearers;
}

void Cassandra5GDB::create_space_and_table(
    std::string space_name, std::string table_name) {
  // setting up the new keyspace for data
  CassError rc = query(
      "CREATE KEYSPACE IF NOT EXISTS " + space_name +
      " WITH REPLICATION = { 'class' : 'SimpleStrategy', 'replication_factor' "
      ": '1' };");

  if (rc != CASS_OK) {
    std::cout << "Failed to set up the new space" << std::endl;
  } else {
    std::cout << "Success to set up the new space" << std::endl;
  }

  rc = query("DROP TABLE IF EXISTS " + space_name + "." + table_name);
  if (rc != CASS_OK) {
    std::cout << "Failed to drop table if exists" << std::endl;
  } else {
    std::cout << "Success to drop table if exists" << std::endl;
  }

  rc = query(
      "CREATE TABLE " + space_name + "." + table_name +
      " (row_id int, extra_id int, supi text PRIMARY KEY, data text);");

  if (rc != CASS_OK) {
    std::cout << "Failed to set up the new table" << std::endl;
  } else {
    std::cout << "Success to set up the new table" << std::endl;
  }

}

std::string to_text(const SMFData& data) {
  return std::string(data);
}

bool Cassandra5GDB::insert_5g_context(
    const SMFData& data, const std::string& ids, int id) {
  /* Bind variables by name this time (this can only be done with prepared
   * statements)*/

  m_insert_5g_statement = cass_prepared_bind(m_insert_5g_prepared);

  // just a placeholder for future use
  cass_statement_bind_int32_by_name(m_insert_5g_statement, "row_id", 0);

  // other data to fill
  cass_statement_bind_int32_by_name(m_insert_5g_statement, "extra_id", id);
  cass_statement_bind_string_by_name(
      m_insert_5g_statement, "supi", ids.c_str());
  cass_statement_bind_string_by_name(
      m_insert_5g_statement, "data", to_text(data).c_str());

  CassFuture* query_future =
      cass_session_execute(m_session, m_insert_5g_statement);

  /* This will block until the query has finished */
  CassError rc = cass_future_error_code(query_future);

  printf("Query result: %s\n", cass_error_desc(rc));

  if (rc != CASS_OK) {
    std::cout << "Failed to insert into table" << std::endl;
  } else {
    std::cout << "Success to insert into table" << std::endl;
  }
  cass_future_free(query_future);
  cass_statement_free(m_insert_5g_statement);

  return rc == CASS_OK;
}

bool Cassandra5GDB::delete_by_internal_id(int id) {
  // not support yet
  return false;
}

bool Cassandra5GDB::delete_by_imsi_bearer_id(std::string imsi, int bearerID) {
  // not support yet
  return false;
}

bool Cassandra5GDB::delete_all() {

  // not support yet
  return false;
}

std::vector<SMFData> Cassandra5GDB::get_all_rows() {
  return select_query(
      "SELECT * FROM " + m_space + "." + m_table_5g_context + ";");
}

std::vector<SMFData> Cassandra5GDB::get_row_by_id(int id) {
  // not support yet
  Logger::flexcn_app().info(
      "[5g smf] not support the feature [get row by internal id]");
  return std::vector<SMFData>{};
}

std::vector<SMFData> Cassandra5GDB::get_row_by_imsi_bearer_id(
    std::string supi, int bearerID) {
  return select_query(
      "SELECT * FROM " + m_space + "." + m_table_5g_context +
      " WHERE supi = \'" + supi + "\' ALLOW FILTERING;");
}
