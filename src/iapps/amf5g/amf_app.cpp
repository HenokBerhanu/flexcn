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

/*! \file amf_app.cpp
 \brief
 \author  Hung NGUYEN
 \company OSA/OAI
 \date 2021
 \email: hung.nguyen@openairinterface.org
 */

#include <arpa/inet.h>
#include <curl/curl.h>
#include <exception>

#include "amf_app.hpp"
#include "logger.hpp"
#include "comm_ops.hpp"

#ifdef WITH_CASSANDRA
#include "cassandra_amf_5g_db.hpp"
#pragma message "CASSANDRA AMF 5G IS ENABLED."
#else
#include "local_amf_5g_db.hpp"
#pragma message "CASSANDRA AMF 5G IS OFF. FALL BACK TO DEFAULT STORAGE."
#endif

#define EVENT_DATA_KEY "reportList" //"eventNotifs"

AMFApp::AMFApp(const std::string& flexcn_ip, int flexcn_port,
            const std::string& amf_ip, int amf_port) : MonitoringAppAPI() {
    m_flexcn_ip = flexcn_ip;
    m_flexcn_port = flexcn_port;
    m_amf_ip = amf_ip;
    m_amf_port = amf_port;
    std::string addr = "";
    m_data_index = 0;

#ifdef WITH_CASSANDRA
    m_database_wrapper = std::make_shared<Cassandra5GAMFDB>(addr);
#else
    m_database_wrapper = std::make_shared<Local5GAMFDB>(addr);
#endif
};

//------------------------------------------------------------------------------
bool trigger_amf_notification_subscribe(const std::string& addr4, int port, 
            const std::string& amf_addr_ipv4, int amf_addr_port) {
  Logger::flexcn_app().debug(
      "Send ITTI msg to SBI task to subscribe to AMF "
      "notification "
      "from FLEXCN");

  std::shared_ptr<itti_n11_subscribe_pdu_session_status_notify> itti_msg =
      std::make_shared<itti_n11_subscribe_pdu_session_status_notify>();

  
  nlohmann::json json_data = {};
  json_data["eventNotifyUri"] =
      addr4 + ":" +
      std::to_string(port) +
      "/flexcn-status-notify/v1/amf001";
  
  json_data["notifyCorrelationId"] = addr4 + ":" +
      std::to_string(port) +
      "/flexcn-status-notify/v1/amf001";

  json_data["nfId"] = "flexcn_amf_tracker_001";
  json_data["supi"]      = "208950000000031";
  json_data["anyUE"] = true;
  json_data["eventList"] = nlohmann::json::array();

  nlohmann::json tmp     = {};
  tmp["type"]           = "TIMEZONE_REPORT";
  tmp["immediateFlag"]  = false;
  tmp["refId"]          = 0;
  json_data["eventList"].push_back(tmp);

  nlohmann::json tmp2     = {};
  tmp2["type"]           = "UES_IN_AREA_REPORT";
  tmp2["immediateFlag"]  = true;
  tmp2["refId"]          = 1;
  json_data["eventList"].push_back(tmp2);

  // COMMUNICATION_FAILURE_REPORT
  nlohmann::json tmp3     = {};
  tmp3["type"]           = "COMMUNICATION_FAILURE_REPORT";
  tmp3["immediateFlag"]  = true;
  tmp3["refId"]          = 2;
  json_data["eventList"].push_back(tmp3);

  nlohmann::json tmp4     = {};
  tmp4["type"]           = "REACHABILITY_REPORT";
  tmp4["immediateFlag"]  = true;
  tmp4["refId"]          = 3;
  json_data["eventList"].push_back(tmp4);

nlohmann::json tmp5     = {};
  tmp5["type"]           = "REGISTRATION_STATE_REPORT";
  tmp5["immediateFlag"]  = true;
  tmp5["refId"]          = 4;
  json_data["eventList"].push_back(tmp5);

nlohmann::json tmp6     = {};
  tmp6["type"]           = "CONNECTIVITY_STATE_REPORT";
  tmp6["immediateFlag"]  = true;
  tmp6["refId"]          = 5;
  json_data["eventList"].push_back(tmp6);


  // // "subscription"
  nlohmann::json send_json_data = {};
  send_json_data["subscription"] = json_data;

  // add new events that we need here!!!!!

  std::string url = amf_addr_ipv4 +
                    ":" + std::to_string(amf_addr_port) +
                    "/namf-evts/v1/subscriptions";

  itti_msg->url       = url;
  itti_msg->json_data = send_json_data;
  Logger::flexcn_app().info(send_json_data.dump().c_str());
  bool ret = subscribe_nf_event_exposure_service(itti_msg, "AMF");

  if (!ret) {
    Logger::flexcn_app().error(
        "Could not send http to AMF");
  }
}

int AMFApp::subcribe_to_nf() {
    bool res = trigger_amf_notification_subscribe(
        m_flexcn_ip, m_flexcn_port, m_amf_ip, m_amf_port
    );
    if (res) return 0;
    return 1;
}

std::string get_supi_from_string(const std::string& str_supi){
  // if string starts with sunstring "imsi-", remove it
  std::string prefix = "imsi-";
  if (!str_supi.compare(0, prefix.size(), prefix))
    return str_supi.substr(prefix.length());
  return str_supi; 
}

bool AMFApp::persist_data(const std::string& data_event, const std::string& id_str, int id_number){
  Logger::flexcn_app().info("[AMF] Add/Merge the following record to database : ");
  Logger::flexcn_app().info(data_event.c_str());

  // parse string to json

  // TODO: valid the source of data
  // store the list of valid sources inside the flexcn-app and verify?
  nlohmann::json json_data;

  // examples of json data: 
  // {
      // "notifyCorrelationId":"192.168.70.142:80/flexcn-status-notify/v1/amf001",
      // "reportList":[
        // {"state":
          // {
            // "active":"TRUE"
          // },
          // "supi":"imsi-208950000000031",
          // "timeStamp":"3849091589",
          // "type":"REGISTRATION_STATE_REPORT"
        // }
      // ]
  // }

  try {
    json_data = nlohmann::json::parse(data_event.c_str());
  } catch (nlohmann::json::parse_error& ex) {
    Logger::flexcn_app().error("Invalid json format:");
    Logger::flexcn_app().error(data_event.c_str());
    Logger::flexcn_app().error(
        "Invalid json format: parse error at byte %i !", ex.byte);
  }

  if (!json_data.contains(EVENT_DATA_KEY)) {
    Logger::flexcn_app().error("Message don't contains %s key!", EVENT_DATA_KEY);
    Logger::flexcn_app().error(data_event.c_str());
    return false;
  }
  if (!json_data[EVENT_DATA_KEY].is_array()) {
    Logger::flexcn_app().error("Event Notifs field is not an array");
    Logger::flexcn_app().error(data_event.c_str());
    return false;
  }

  // TODO: must check of json object of eventNotifs is array
  for (auto j : json_data[EVENT_DATA_KEY]) {
    if (!j.contains("supi")) {
      Logger::flexcn_app().info("Event doesn't contains supi");
      Logger::flexcn_app().info(j.dump().c_str());
      // quit in this case
      return false; 
    }

    // adding this to database
    bool success = false;
    try{
      std::string type = j["type"].get<std::string>();
      if( type == "REGISTRATION_STATE_REPORT"){
        std::string supi = get_supi_from_string(j["supi"].get<std::string>());
        Logger::flexcn_app().info("REGISTRATION_STATE_REPORT:");
        Logger::flexcn_app().info(supi.c_str());
        m_database_wrapper->insert_5g_context(data_event, supi, m_data_index);
        //index is rotated after a long period of time
        //TODO: in production, need a better (unique) index 
        ++m_data_index;
      }
      // other types of event are not supported!
      // missing imsi 
      // {"notifyCorrelationId":"192.168.70.142:80/flexcn-status-notify/v1/amf001",
      // "reportList":[{"reachability":"REACHABLE","state":{"active":"TRUE"},
      // "supi":"imsi-","timeStamp":"3849091589","type":"REACHABILITY_REPORT"}]}
      else if (type == "REACHABILITY_REPORT"){

      }
      // can't trigger this event from CN
      else if (type == "CONNECTIVITY_STATE_REPORT"){

      }

      else {
        Logger::flexcn_app().info("Cannot recongize this event type: %s", type.c_str());
      }
    }
    catch (std::exception&   e){
      Logger::flexcn_app().error("Error format of nortification as expected");
      Logger::flexcn_app().error(e.what());
    }
    //TODO: Data fusion
  }
}

std::string AMFApp::retrieve_data_by_id(int id){
    Logger::flexcn_app().error("AMF iAPP does not support retrieve_data_by_id");
    return "";
}

std::string AMFApp::retrieve_data_by_key(const std::string& supi){
    std::vector<AMFData> obj = m_database_wrapper->get_row_by_key(supi, 0);
    if (obj.size() > 0)
    {
        nlohmann::json j = {};
        nlohmann::to_json(j, obj);
        // TODO: clear data once it is returned to the xapp
        m_database_wrapper->delete_by_key(supi, -1);

        return j.dump(4).c_str();
    }
    Logger::flexcn_app().error("AMF iAPP does not have the data that is related to key [ %s ]", supi.c_str());
    return "";
}

std::string AMFApp::retrieve_all_data(){
    std::vector<AMFData> obj = m_database_wrapper->get_all_rows();
    
    if (obj.size() > 0)
    {
        nlohmann::json j = {};
        nlohmann::to_json(j, obj);
        // // clear data once it is returned to the xapp
        // m_database_wrapper->delete_by_key(supi, -1);
        return j.dump(4).c_str();
    }
    
    return "";
}   
