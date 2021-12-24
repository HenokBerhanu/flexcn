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

/*! \file local_db.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include "local_db.hpp"
#include "logger.hpp"

#include <iostream>
#include <exception>


Local4GDB::Local4GDB(const std::string& database_ip) : DatabaseWrapper(database_ip), m_main_database_4g(), m_imsi_bearer_id_to_main_id(){
}

Local4GDB::~Local4GDB() {

  std::cout << "Clean alll" << std::endl;
}

bool Local4GDB::insert_4g_context(const Bearer& bearer, int id){
  // add the main database
  // TODO: verify if imsi, bearer id  valid otherwise returns false
  std::string imsi = bearer.getImsi();
  unsigned int bearer_id = (unsigned int) bearer.getEpsBearerId();

  // TODO: check if move works properly
  // TODO: verify if m_4gid available  
  m_main_database_4g.insert(std::pair<unsigned int, Bearer>(id, std::move(bearer)));
  m_imsi_bearer_id_to_main_id[imsi].insert(std::pair<unsigned int, unsigned int>(bearer_id, id)); 
  
  return true;
}

bool Local4GDB::delete_by_internal_id(int id) {
   try {
    std::string imsi = m_main_database_4g[id].getImsi();
    unsigned int bearer_id = (unsigned int) m_main_database_4g[id].getEpsBearerId();
    m_main_database_4g.erase(id);
    m_imsi_bearer_id_to_main_id[imsi].erase(bearer_id);
    if (m_imsi_bearer_id_to_main_id[imsi].empty())
    {
        m_imsi_bearer_id_to_main_id.erase(imsi);
    }
    return true;
  }
  catch (std::exception& e){
    Logger::flexcn_app().error(e.what());
    return false;      
  }
  return true;
}

bool Local4GDB::delete_by_imsi_bearer_id(std::string imsi, int bearer_id) {
  try {
    
    if (m_imsi_bearer_id_to_main_id.find(imsi) == m_imsi_bearer_id_to_main_id.end())
    {
      // this imsi is not in the database
      return false; 
    }
    std::cout << "imsi bearer " << imsi << bearer_id << std::endl;

    m_main_database_4g.erase(m_imsi_bearer_id_to_main_id[imsi][bearer_id]);
    m_imsi_bearer_id_to_main_id[imsi].erase(bearer_id);
    if (m_imsi_bearer_id_to_main_id[imsi].empty())
    {
        m_imsi_bearer_id_to_main_id.erase(imsi);
    }

    return true;
  } catch (std::exception& e){
    Logger::flexcn_app().error(e.what());
    return false;      
  }

  return true;
}

bool Local4GDB::delete_all() {
  m_main_database_4g.clear();
  m_imsi_bearer_id_to_main_id.clear();
  return true;
}

std::vector<Bearer> Local4GDB::get_all_rows(){
   std::vector<Bearer> stats ;
  for (const auto& [_, value] : m_main_database_4g) {
      stats.push_back(value);
  }
  return stats;
}

std::vector<Bearer> Local4GDB::get_row_by_id(int id){
   std::vector<Bearer> stats;

  try {
      
      stats.push_back(Bearer(m_main_database_4g[id]));
  } 
  catch (std::exception& e){
      Logger::flexcn_app().error(e.what());      
  }
  return stats;
}

std::vector<Bearer> Local4GDB::get_row_by_imsi_bearer_id(std::string imsi, int bearerID){
std::vector<Bearer> stats;
    // for (const auto & [key, value] : m_imsi_bearer_id_to_main_id[imsi])
    // {
        stats.push_back(Bearer(m_main_database_4g[m_imsi_bearer_id_to_main_id[imsi][bearerID]]));
    // }  
  return stats;
}

