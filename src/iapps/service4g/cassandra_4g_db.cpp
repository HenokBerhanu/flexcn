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

/*! \file cassandra_4g_db.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include "cassandra_4g_db.hpp"
#include <iostream>

Cassandra4GDB::Cassandra4GDB(const std::string& database_ip)
    : DatabaseWrapper(database_ip) {
  /* Setup and connect to cluster */
  m_cluster = cass_cluster_new();
  m_session = cass_session_new();

  //
  m_database_IP      = database_ip;  // "192.168.74.3"
  m_space            = "store";
  m_table_4g_context = "context_4G";

  /* Add contact points */
  cass_cluster_set_contact_points(m_cluster, m_database_IP.c_str());

  /* Provide the cluster object as configuration to connect the session */
  m_connect_future = cass_session_connect(m_session, m_cluster);

  /* This operation will block until the result is ready */
  CassError rc = cass_future_error_code(m_connect_future);

  printf("Connect result: %s\n", cass_error_desc(rc));

  create_space_and_table(m_space, m_table_4g_context);
  setup_insert_query();
}

Cassandra4GDB::~Cassandra4GDB() {
  /* Statement objects can be freed immediately after being executed */
  /* The prepared object must be freed */
  cass_prepared_free(m_insert_4g_prepared);
  cass_session_free(m_session);
  cass_cluster_free(m_cluster);
  cass_future_free(m_connect_future);

  std::cout << "Clean alll" << std::endl;
}

void Cassandra4GDB::setup_insert_query() {
  std::string str_insert_4g_query =
      "INSERT INTO " + m_space + "." + m_table_4g_context +
      " (row_id, eps_bearer_id,eps_meter_id,imsi,s1_ul_teid, s1_dl_teid, "
      "ue_ip,enb_ip) VALUES (?, ?, ?, ?, ?, ?, ?, ?);";  // row_id
  // CassString insert_query = cass_string_init(str_insert_4g_query.c_str());

  /* Prepare the statement on the Cassandra cluster */
  CassFuture* prepare_future =
      cass_session_prepare(m_session, str_insert_4g_query.c_str());

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
  m_insert_4g_prepared = cass_future_get_prepared(prepare_future);

  /* The future can be freed immediately after getting the prepared object */
  cass_future_free(prepare_future);
  std::cout << "Success to setting up the insert query" << std::endl;
}

CassError Cassandra4GDB::query(std::string str_query) {
  // example of query / "INSERT INTO example (key, value) VALUES ('abc', 123)"

  /* Create a statement with zero parameters */
  CassStatement* statement = cass_statement_new(str_query.c_str(), 0);

  CassFuture* query_future = cass_session_execute(m_session, statement);

  // // check if query contains SELECT

  /* Statement objects can be freed immediately after being executed */
  cass_statement_free(statement);

  /* This will block until the query has finished */
  CassError rc = cass_future_error_code(query_future);

  // printf("Query result: %s\n", cass_error_desc(rc));
  // rc.

  cass_future_free(query_future);
  return rc;
}

std::vector<Bearer> Cassandra4GDB::select_query(std::string str_query) {
  /* Build statement and execute query */

  CassStatement* statement = cass_statement_new(str_query.c_str(), 0);

  CassFuture* result_future = cass_session_execute(m_session, statement);

  std::vector<Bearer> v_b;
  if (cass_future_error_code(result_future) == CASS_OK) {
    /* Retrieve result set and iterate over the rows */
    const CassResult* result = cass_future_get_result(result_future);
    v_b                      = get_bearers_from_cass_result(result);

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

int Cassandra4GDB::query_index(std::string imsi, int bearerID) {
  std::string query = "SELECT row_id FROM " + m_space + "." +
                      m_table_4g_context + "_by_row_id WHERE imsi=\'" + imsi +
                      "\' and eps_bearer_id= " + std::to_string(bearerID) + ";";
  std::cout << query << std::endl;
  CassStatement* statement = cass_statement_new(query.c_str(), 0);

  CassFuture* result_future = cass_session_execute(m_session, statement);

  const CassResult* result = cass_future_get_result(result_future);

  /* If there was an error then the result won't be available */
  if (result == NULL) {
    cass_future_free(result_future);
    return -1;
  }

  /* The future can be freed immediately after getting the result object */
  cass_future_free(result_future);

  /* This can be used to retrieve the first row of the result */
  const CassRow* row = cass_result_first_row(result);

  if (row) {
    /* Now we can retrieve the column values from the row */
    cass_int32_t value;

    /* Get the column value of "value" by name */
    cass_value_get_int32(cass_row_get_column_by_name(row, "row_id"), &value);

    /* This will free the result as well as the string pointed to by 'key' */
    cass_result_free(result);

    return value;
  }

  std::cout << "no item match this condition" << std::endl;

  /* This will free the result as well as the string pointed to by 'key' */
  cass_result_free(result);

  return -1;
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

Bearer Cassandra4GDB::get_a_bearer_from_a_cass_row(const CassRow* row) {
  Bearer br;

  const CassValue* value = cass_row_get_column_by_name(row, "eps_bearer_id");
  cass_int32_t eps_bearer_id;
  cass_value_get_int32(value, &eps_bearer_id);
  br.setEpsBearerId(eps_bearer_id);

  value = cass_row_get_column_by_name(row, "eps_meter_id");
  cass_int32_t eps_meter_id;
  cass_value_get_int32(value, &eps_meter_id);
  br.setEpsMeterId(eps_meter_id);

  std::string imsi = get_string_from_cass_value(row, "imsi");
  br.setImsi(imsi);

  std::string s1_ul_teid = get_string_from_cass_value(row, "s1_ul_teid");
  br.setS1UlTeid(s1_ul_teid);

  std::string s1_dl_teid = get_string_from_cass_value(row, "s1_dl_teid");
  br.setS1DlTeid(s1_dl_teid);

  std::string ue_ip = get_string_from_cass_value(row, "ue_ip");
  br.setUeIp(ue_ip);

  std::string enb_ip = get_string_from_cass_value(row, "enb_ip");
  br.setEnbIp(enb_ip);
  return br;
}

std::vector<Bearer> Cassandra4GDB::get_bearers_from_cass_result(
    const CassResult* result) {
  std::vector<Bearer> v_bearers;
  CassIterator* rows = cass_iterator_from_result(result);

  while (cass_iterator_next(rows)) {
    const CassRow* row = cass_iterator_get_row(rows);
    Bearer br          = get_a_bearer_from_a_cass_row(row);
    v_bearers.push_back(br);
  }
  cass_iterator_free(rows);
  return v_bearers;
}

void Cassandra4GDB::create_space_and_table(
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
      " (row_id int PRIMARY KEY, eps_bearer_id int, eps_meter_id int, imsi "
      "text, s1_ul_teid text, s1_dl_teid text, ue_ip text, enb_ip text);");  // , row_id int

  if (rc != CASS_OK) {
    std::cout << "Failed to set up the new table" << std::endl;
  } else {
    std::cout << "Success to set up the new table" << std::endl;
  }

  rc = query(
      "DROP TABLE IF EXISTS " + space_name + "." + table_name + "_by_row_id");
  if (rc != CASS_OK) {
    std::cout << "Failed to drop table if exists" << std::endl;
  } else {
    std::cout << "Success to drop table if exists" << std::endl;
  }

  rc = query(
      "CREATE TABLE " + space_name + "." + table_name +
      "_by_row_id (row_id int, eps_bearer_id int, imsi text, PRIMARY KEY(imsi, "
      "eps_bearer_id));");  // , row_id int

  if (rc != CASS_OK) {
    std::cout << "Failed to set up the new table" << std::endl;
  } else {
    std::cout << "Success to set up the new table" << std::endl;
  }
}

bool Cassandra4GDB::insert_4g_context(const Bearer& bearer, int id) {
  /* Bind variables by name this time (this can only be done with prepared
   * statements)*/

  m_insert_4g_statement = cass_prepared_bind(m_insert_4g_prepared);

  cass_statement_bind_int32_by_name(m_insert_4g_statement, "row_id", id);

  cass_statement_bind_int32_by_name(
      m_insert_4g_statement, "eps_bearer_id", bearer.getEpsBearerId());
  cass_statement_bind_int32_by_name(
      m_insert_4g_statement, "eps_meter_id", bearer.getEpsMeterId());

  /// (optional) Type of service including DSCP and ECN.
  // int64_t getTos() const;

  cass_statement_bind_string_by_name(
      m_insert_4g_statement, "imsi", bearer.getImsi().c_str());

  std::cout << "INSERT INTO " + m_space + "." + m_table_4g_context +
                   "_by_row_id (row_id, eps_bearer_id,imsi) VALUES (" +
                   std::to_string(id) + "," +
                   std::to_string(bearer.getEpsBearerId()) + "," +
                   bearer.getImsi() + " );"
            << std::endl;
  CassError rc = query(
      "INSERT INTO " + m_space + "." + m_table_4g_context +
      "_by_row_id (row_id, eps_bearer_id,imsi) VALUES (" + std::to_string(id) +
      "," + std::to_string(bearer.getEpsBearerId()) + ",\'" + bearer.getImsi() +
      "\' );");

  if (rc != CASS_OK) {
    std::cout << "Failed to insert into table by row id" << std::endl;
  }

  /// S1 downlink tunnel ID
  cass_statement_bind_string_by_name(
      m_insert_4g_statement, "s1_ul_teid", bearer.getS1UlTeid().c_str());

  /// S1 uplink tunnel ID
  cass_statement_bind_string_by_name(
      m_insert_4g_statement, "s1_dl_teid", bearer.getS1DlTeid().c_str());

  /// IP address of UE
  cass_statement_bind_string_by_name(
      m_insert_4g_statement, "ue_ip", bearer.getUeIp().c_str());

  /// IP address of eNodeB
  cass_statement_bind_string_by_name(
      m_insert_4g_statement, "enb_ip", bearer.getEnbIp().c_str());

  /* Execute statement (same a the non-prepared code) */
  CassFuture* query_future =
      cass_session_execute(m_session, m_insert_4g_statement);

  /* This will block until the query has finished */
  rc = cass_future_error_code(query_future);

  printf("Query result: %s\n", cass_error_desc(rc));

  if (rc != CASS_OK) {
    std::cout << "Failed to insert into table" << std::endl;
  } else {
    std::cout << "Success to insert into table" << std::endl;
  }
  cass_future_free(query_future);
  cass_statement_free(m_insert_4g_statement);

  return rc == CASS_OK;
}

bool Cassandra4GDB::delete_by_internal_id(int id) {
  std::vector<Bearer> brs = get_row_by_id(id);
  std::cout << "Found " << brs.size() << " bearers" << std::endl;
  if (brs.size() > 0) {
    std::string imsi = brs[0].getImsi();
    int bearerID     = brs[0].getEpsBearerId();
    CassError rc     = query(
        "DELETE FROM " + m_space + "." + m_table_4g_context +
        "_by_row_id WHERE imsi = \'" + imsi +
        "\' and eps_bearer_id = " + std::to_string(bearerID) + " IF EXISTS;");

    if (rc != CASS_OK) {
      std::cout << "Failed to delete index table by id " << id << std::endl;
    }
  };

  CassError rc = query(
      "DELETE FROM " + m_space + "." + m_table_4g_context +
      " WHERE row_id = " + std::to_string(id) + " IF EXISTS;");

  if (rc != CASS_OK) {
    std::cout << "Failed to delete by id " << id << std::endl;
  } else {
    std::cout << "Success to delete by id " << id << std::endl;
  }

  return rc == CASS_OK;
}

bool Cassandra4GDB::delete_by_imsi_bearer_id(std::string imsi, int bearerID) {
  int index = query_index(imsi, bearerID);
  if (index < 0) {
    std::cout << "Don't find imsi " << imsi << " bearer " << bearerID
              << std::endl;
    return false;
  }
  std::string del_query = "DELETE FROM " + m_space + "." + m_table_4g_context +
                          "_by_row_id WHERE imsi = \'" + imsi +
                          "\' and eps_bearer_id = " + std::to_string(bearerID) +
                          " IF EXISTS;";
  std::cout << del_query << std::endl;

  CassError rc = query(del_query);

  if (rc != CASS_OK) {
    std::cout << "Failed to delete index table by id " << index << std::endl;
  }
  rc = query(
      "DELETE FROM " + m_space + "." + m_table_4g_context +
      " WHERE row_id = " + std::to_string(index));

  if (rc != CASS_OK) {
    std::cout << "Failed to delete by id " << index << std::endl;
  } else {
    std::cout << "Success to delete by id " << index << std::endl;
  }
  return rc == CASS_OK;
}

bool Cassandra4GDB::delete_all() {
  CassError rc = query(" TRUNCATE " + m_space + "." + m_table_4g_context + ";");
  rc =
      query(" TRUNCATE " + m_space + "." + m_table_4g_context + "_by_row_id ;");
  if (rc != CASS_OK) {
    std::cout << "Failed to clear 4G data" << std::endl;
  } else {
    std::cout << "Success to clear 4G data" << std::endl;
  }

  return rc == CASS_OK;
}

std::vector<Bearer> Cassandra4GDB::get_all_rows() {
  return select_query(
      "SELECT * FROM " + m_space + "." + m_table_4g_context + ";");
}

std::vector<Bearer> Cassandra4GDB::get_row_by_id(int id) {
  return select_query(
      "SELECT * FROM " + m_space + "." + m_table_4g_context +
      " WHERE row_id = " + std::to_string(id) + ";");
}

std::vector<Bearer> Cassandra4GDB::get_row_by_imsi_bearer_id(
    std::string imsi, int bearerID) {
  return select_query(
      "SELECT * FROM " + m_space + "." + m_table_4g_context +
      " WHERE imsi = \'" + imsi + "\' AND eps_bearer_id = " +
      std::to_string(bearerID) + " ALLOW FILTERING;");
}
