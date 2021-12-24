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

/*! \file local_5g_db.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include "local_5g_db.hpp"
#include "logger.hpp"

#include <iostream>
#include <exception>

Local5GDB::Local5GDB(const std::string& database_ip)
    : Database5GWrapper(database_ip), m_main_database_5g() {}

Local5GDB::~Local5GDB() {
  std::cout << "Clean alll" << std::endl;
}

bool Local5GDB::insert_5g_context(
    const SMFData& data, const std::string& ids, int id) {
  m_main_database_5g[ids][id] = std::move(data);
  return true;
}

bool Local5GDB::delete_by_internal_id(int id) {
  Logger::flexcn_app().info(
      "Function delete_by_internal_id() of SMF App is NOT "
      "supported/implemented");
  return false;
}

bool Local5GDB::delete_by_key(std::string key, int bearer_id) {
  try {
    m_main_database_5g.erase(key);
    return true;
  } catch (std::exception& e) {
    Logger::flexcn_app().error(e.what());
    return false;
  }
  return false;
}

bool Local5GDB::delete_all() {
  m_main_database_5g.clear();
  return true;
}

std::vector<SMFData> Local5GDB::get_all_rows() {
  std::vector<SMFData> stats;
  for (const auto& [_, value] : m_main_database_5g) {
    for (const auto& [_, i_value] : value) {
      stats.push_back(i_value);
    }
  }
  return stats;
}

std::vector<SMFData> Local5GDB::get_row_by_id(int id) {
  std::vector<SMFData> stats;
  Logger::flexcn_app().info(
      "Function get_row_by_id() of SMF App is NOT supported/implemented");
  return stats;
}

std::vector<SMFData> Local5GDB::get_row_by_key(std::string supi, int bearerID) {
  std::vector<SMFData> stats;
  for (const auto& [_, i_value] : m_main_database_5g[supi]) {
    stats.push_back(i_value);
  }
  return stats;
}
