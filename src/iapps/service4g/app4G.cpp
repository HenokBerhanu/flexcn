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

/*! \file app4G.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include <iostream>
#include <sstream>
#include <exception>

#include "app4G.hpp"
#include "database_wrapper.hpp"

#ifdef WITH_CASSANDRA
#include "cassandra_4g_db.hpp"
#pragma message "CASSANDRA 4G IS ENABLED."
#else
#include "local_db.hpp"
#pragma message "CASSANDRA 4G IS OFF. FALLED BACK TO DAFAULT STORAGE."
#endif

#include "logger.hpp"



App4G::App4G(const std::string& addr) {

#ifdef WITH_CASSANDRA
    //cassandra
    m_database_wrapper = std::make_shared<Cassandra4GDB>(addr);
#else     
    //local database
    m_database_wrapper = std::make_shared<Local4GDB>(addr);
#endif
    
    // TODO: handle max number of id
    m_4gid = 1;
}

App4G::~App4G() {

}

bool App4G::add_bearer(Bearer &bearer){
  bool success = m_database_wrapper->insert_4g_context(bearer, m_4gid);
  if (success) m_4gid++;
  return success;   
}

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }
    return result;
}


bool App4G::delete_a_single_bearer_by_imsi_bearer(const std::string &imsiBearer){

  try {
    std::cout << "imsi bearer " << imsiBearer << std::endl;
    std::vector<std::string> imsi_and_bearer_id =  split(imsiBearer, ',');
    std::string imsi = imsi_and_bearer_id[0];
    unsigned int bearer_id = (unsigned int) std::stoul(imsi_and_bearer_id[1]);
    return m_database_wrapper->delete_by_imsi_bearer_id(imsi, bearer_id);
  } catch (std::exception& e){
    Logger::flexcn_app().error(e.what());
    return false;      
  }

  return true;
}

bool App4G::delete_a_single_bearer_by_id(const std::string &id){
  try {
    unsigned int internal_id = (unsigned int) std::stoul(id,nullptr,0);
    return m_database_wrapper->delete_by_internal_id(internal_id);
  }
  catch (std::exception& e){
    Logger::flexcn_app().error(e.what());
    return false;      
  }
  return true;
}

bool App4G::delete_all_bearers(){
  return m_database_wrapper->delete_all();
}

std::vector<Bearer> App4G::get_stats(){
  std::vector<Bearer> stats = m_database_wrapper->get_all_rows();
  return stats;
}

std::vector<Bearer> App4G::get_stats_by_imsi_bearer(const std::string &imsiBearer)
{
  Logger::flexcn_app().info("Received this request: ", imsiBearer.c_str());
  std::vector<Bearer> stats;
  try {
    std::vector<std::string> imsi_and_bearer_id =  split(imsiBearer, ',');
    std::string imsi = imsi_and_bearer_id[0];
    unsigned int bearer_id = (unsigned int) std::stoul(imsi_and_bearer_id[1], nullptr, 0);
    stats = m_database_wrapper->get_row_by_imsi_bearer_id(imsi, bearer_id);
  } 
  catch (std::exception& e){
      Logger::flexcn_app().error(e.what());      
  }  
  return stats;
}

std::vector<Bearer> App4G::get_stats_by_id(const std::string &id){
  std::vector<Bearer> stats;
  std::cout << "Get data for id :" << id << std::endl;
  try {
      unsigned int uinteger_id = (unsigned int) std::stol(id);
      Logger::flexcn_app().info("Get data for id : %d", uinteger_id);
      stats = m_database_wrapper->get_row_by_id(uinteger_id);
  } 
  catch (std::exception& e){
      Logger::flexcn_app().error(e.what());      
  }

  return stats;
} 
