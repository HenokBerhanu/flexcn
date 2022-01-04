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

/*! \file smf_app.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include <arpa/inet.h>
#include <curl/curl.h>
#include <exception>

#include "smf_app.hpp"
#include "logger.hpp"
#include "comm_ops.hpp"

#ifdef WITH_CASSANDRA
#include "cassandra_5g_db.hpp"
#pragma message "CASSANDRA 5G IS ENABLED."
#else
#include "local_5g_db.hpp"
#pragma message "CASSANDRA 5G IS OFF. FALLED BACK TO DAFAULT STORAGE."
#endif
SMFApp::SMFApp(
    const std::string& flexcn_ip, int flexcn_port, const std::string& smf_ip,
    int smf_port)
    : MonitoringAppAPI() {
  m_flexcn_ip   = flexcn_ip;
  m_flexcn_port = flexcn_port;

  m_smf_ip   = smf_ip;
  m_smf_port = smf_port;

  std::string addr = "";

#ifdef WITH_CASSANDRA

#else
  m_database_wrapper = std::make_shared<Local5GDB>(addr);
#endif
};

//------------------------------------------------------------------------------
bool trigger_pdu_session_status_notification_subscribe(
    const std::string& addr4, int port, const std::string& smf_addr_ipv4,
    int smf_addr_port) {
  Logger::flexcn_app().debug(
      "Send msg to subscribe to PDU Session Status notification from FLEXCN");

  std::shared_ptr<itti_n11_subscribe_pdu_session_status_notify> itti_msg =
      std::make_shared<itti_n11_subscribe_pdu_session_status_notify>();

  nlohmann::json json_data = {};
  json_data["notifUri"]    = std::string(addr4) + ":" + std::to_string(port) +
                          "/flexcn-status-notify/v1/notifid01";

  json_data["notifId"] = "notifid01";

  json_data["supi"]      = "208950000000031";
  json_data["eventSubs"] = nlohmann::json::array();
  nlohmann::json tmp     = {};
  tmp["event"]           = "PDU_SES_REL";

  nlohmann::json tmp2 = {};
  tmp2["event"]       = "UE_IP_CH";

  nlohmann::json tmp3 = {};
  tmp3["event"]       = "DDDS";

  nlohmann::json tmp4 = {};
  tmp4["event"]       = "PLMN_CH";

  nlohmann::json tmp5 = {};
  tmp5["event"]       = "FLEXCN";

  json_data["eventSubs"].push_back(tmp);
  json_data["eventSubs"].push_back(tmp2);
  json_data["eventSubs"].push_back(tmp3);
  json_data["eventSubs"].push_back(tmp4);
  json_data["eventSubs"].push_back(tmp5);

  std::string url = std::string(smf_addr_ipv4) + ":" +
                    std::to_string(smf_addr_port) +
                    "/nsmf_event-exposure/v1/subscriptions";

  itti_msg->url       = url;
  itti_msg->json_data = json_data;
  Logger::flexcn_app().info(json_data.dump().c_str());

  bool res = subscribe_nf_event_exposure_service(itti_msg, "SMF");

  // if return failed.
  return res;
}

int SMFApp::subcribe_to_nf() {
  // settup all necessary info
  std::string addr4         = m_flexcn_ip;
  int port                  = m_flexcn_port;
  std::string smf_addr_ipv4 = m_smf_ip;
  int smf_addr_port         = m_smf_port;

  bool res = trigger_pdu_session_status_notification_subscribe(
      addr4, port, smf_addr_ipv4, smf_addr_port);

  if (res) return 0;
  return 1;
}

bool SMFApp::persist_data(
    const std::string& data_event, const std::string& id_str, int id_number) {
  Logger::flexcn_app().info("Add/Merge the following record to database : ");
  Logger::flexcn_app().info(data_event.c_str());

  // parse string to json

  // TODO: valid the source of data
  // store the list of valid sources inside the flexcn-app and verify?
  nlohmann::json json_data;
  try {
    json_data = nlohmann::json::parse(data_event.c_str());
  } catch (nlohmann::json::parse_error& ex) {
    Logger::flexcn_app().error("Invalid json format:");
    Logger::flexcn_app().error(data_event.c_str());
    Logger::flexcn_app().error(
        "Invalid json format: parse error at byte %i !", ex.byte);
  }

  if (!json_data.contains("eventNotifs")) {
    Logger::flexcn_app().error("Message don't contains eventNotifs key!");
    Logger::flexcn_app().error(data_event.c_str());
    return false;
  }
  if (!json_data["eventNotifs"].is_array()) {
    Logger::flexcn_app().error("Event Notifs field is not an array");
    Logger::flexcn_app().error(data_event.c_str());
    return false;
  }

  // TODO: must check of json object of eventNotifs is array
  for (auto j : json_data["eventNotifs"]) {
    if (!j.contains("supi")) {
      Logger::flexcn_app().info("Event doesn't contains supi");
      Logger::flexcn_app().info(j.dump().c_str());
      // quit in this case
      return false;
    }

    bool success = false;
    try {
      Logger::flexcn_app().info(j["supi"].dump().c_str());
      Logger::flexcn_app().info(j["pduSeId"].dump().c_str());
      m_database_wrapper->insert_5g_context(
          data_event, j["supi"].get<std::string>(), j["pduSeId"].get<int>());

    } catch (std::exception& e) {
      Logger::flexcn_app().error("Error format of nortification as expected");
      Logger::flexcn_app().error(e.what());
    }
  }
}
std::string SMFApp::retrieve_data_by_id(int id) {
  Logger::flexcn_app().error("SMF iAPP does not support retrieve_data_by_id");
  return "";
}

std::string SMFApp::retrieve_data_by_key(const std::string& supi) {
  std::vector<SMFData> obj = m_database_wrapper->get_row_by_key(supi, 0);
  if (obj.size() > 0) {
    nlohmann::json j = {};
    nlohmann::to_json(j, obj);
    // TODO: clear data once it is returned to the xapp
    m_database_wrapper->delete_by_key(supi, -1);

    return j.dump(4).c_str();
  }
  Logger::flexcn_app().error(
      "SMF iAPP does not have the data that is related to key [ %s ]",
      supi.c_str());
  return "";
}

std::string SMFApp::retrieve_all_data() {
  std::vector<SMFData> obj = m_database_wrapper->get_all_rows();
  if (obj.size() > 0) {
    nlohmann::json j = {};
    nlohmann::to_json(j, obj);
    return j.dump(4).c_str();
  }
  return "";
}
