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

/*! \file flexcn_data_item.hpp
 \brief
 \author  Hung NGUYEN
 \company Eurecom
 \date 2021
 \email: hnguyen@eurecom.fr
 */

#ifndef FILE_FLEXCN_DATA_ITEM_HPP_SEEN
#define FILE_FLEXCN_DATA_ITEM_HPP_SEEN


#include "DnaiChangeType.h"
// #include "DddStatus.h"
#include <string>
#include "Ipv6Prefix.h"
#include "SmfEvent.h"
#include "PlmnId.h"
#include "RouteToLocation.h"
#include "AccessType.h"
#include <nlohmann/json.hpp>
#include "EventNotification.h"
#include "DddStatus.h"


// #include "3gpp_129.244.h"
// #include "3gpp_24.501.h"
#include "common_root_types.h"
#include "conversions.hpp"
// #include "3gpp_29.244.h"



// using namespace oai::smf_server::model;
// typedef std::string DddStatus; // only 3 values: - BUFFERED - TRANSMITTED - DISCARDED 

namespace oai {
namespace flexcn_server {
namespace model {

struct fteid {
  std::string ipv4;
  std::string ipv6;
}; 

void to_json(nlohmann::json& j, const fteid& p);

void from_json(const nlohmann::json& j, fteid& p);

 struct qos_flow {
   uint8_t qfi;
   fteid upf_addr;
   fteid an_addr;
 };

void to_json(nlohmann::json& j, const qos_flow& p);

void from_json(const nlohmann::json& j, qos_flow& p);


namespace pfcp {
  struct node_id_s {
  uint8_t spare : 4;
  uint8_t node_id_type : 4;
  union {
    struct in_addr ipv4_address;
    struct in6_addr ipv6_address;
  } u1;
  std::string fqdn;  // should be in union but problem with virtual ~
  bool operator==(const struct node_id_s& i) const {
    if ((i.node_id_type == this->node_id_type) &&
        (i.u1.ipv4_address.s_addr == this->u1.ipv4_address.s_addr) &&
        (i.fqdn == this->fqdn) &&
        (i.u1.ipv6_address.s6_addr32[0] ==
         this->u1.ipv6_address.s6_addr32[0]) &&
        (i.u1.ipv6_address.s6_addr32[1] ==
         this->u1.ipv6_address.s6_addr32[1]) &&
        (i.u1.ipv6_address.s6_addr32[2] ==
         this->u1.ipv6_address.s6_addr32[2]) &&
        (i.u1.ipv6_address.s6_addr32[3] ==
         this->u1.ipv6_address.s6_addr32[3])) {
      return true;
    } else {
      return false;
    }
  };
};
typedef struct node_id_s node_id_t;

//-------------------------------------
// 8.2.3 F-TEID
struct fteid_s {
  uint8_t chid : 1;
  uint8_t ch : 1;
  uint8_t v6 : 1;
  uint8_t v4 : 1;
  teid_t teid;
  struct in_addr ipv4_address;
  struct in6_addr ipv6_address;
  uint8_t choose_id;

  bool operator==(const struct fteid_s& f) const {
    return (teid == f.teid) and
           (ipv4_address.s_addr == f.ipv4_address.s_addr) and
           (chid == f.chid) and (ch == f.ch) and (choose_id == f.choose_id) and
           (ipv6_address.s6_addr32[0] == f.ipv6_address.s6_addr32[0]) and
           (ipv6_address.s6_addr32[1] == f.ipv6_address.s6_addr32[1]) and
           (ipv6_address.s6_addr32[2] == f.ipv6_address.s6_addr32[2]) and
           (ipv6_address.s6_addr32[3] == f.ipv6_address.s6_addr32[3]) and
           (v4 == f.v4) and (v6 == f.v6);
  }

  bool operator=(const struct fteid_s& f) {
    v4                  = f.v4;
    v6                  = f.v6;
    chid                = f.chid;
    ch                  = f.ch;
    choose_id           = f.choose_id;
    teid                = f.teid;
    ipv4_address.s_addr = f.ipv4_address.s_addr;
    ipv6_address        = f.ipv6_address;
    // ipv6_address.s6_addr32[0] = f.ipv6_address.s6_addr32[0];
    // ipv6_address.s6_addr32[1] = f.ipv6_address.s6_addr32[1];
    // ipv6_address.s6_addr32[2] = f.ipv6_address.s6_addr32[2];
    // ipv6_address.s6_addr32[3] = f.ipv6_address.s6_addr32[3];
  }

  std::string toString() const {
    std::string s = {};
    if ((v4) || (v6)) {
      s.append("TEID=").append(std::to_string(teid));
      if (v4) {
        s.append(", IPv4=").append(conv::toString(ipv4_address));
      }
      if (v6) {
        s.append(", IPv6=").append(conv::toString(ipv6_address));
      }
    } else {
      s.append("null_fteid");
    }
    return s;
  }

  bool is_zero() const { return ((!v4) and (!v6)); }
};

typedef struct fteid_s fteid_t;


//-------------------------------------
// 8.2.37 F-SEID
typedef struct fseid_s {
  uint8_t spare : 6;
  uint8_t v4 : 1;
  uint8_t v6 : 1;
  uint64_t seid;
  struct in_addr ipv4_address;
  struct in6_addr ipv6_address;

  bool operator==(const struct fseid_s& i) const {
    if ((i.seid == this->seid) && (i.v4 == this->v4) &&
        (i.ipv4_address.s_addr == this->ipv4_address.s_addr) &&
        (i.v6 == this->v6) &&
        (i.ipv6_address.s6_addr32[0] == this->ipv6_address.s6_addr32[0]) &&
        (i.ipv6_address.s6_addr32[1] == this->ipv6_address.s6_addr32[1]) &&
        (i.ipv6_address.s6_addr32[2] == this->ipv6_address.s6_addr32[2]) &&
        (i.ipv6_address.s6_addr32[3] == this->ipv6_address.s6_addr32[3])) {
      return true;
    } else {
      return false;
    }
  };
  bool operator<(const struct fseid_s& i) const {
    if (i.seid < this->seid)
      return true;
    else if (i.seid > this->seid)
      return false;
    if (i.v4 == this->v4) {
      if (i.ipv4_address.s_addr > this->ipv4_address.s_addr)
        return true;
      else if (i.ipv4_address.s_addr < this->ipv4_address.s_addr)
        return false;
    } else if (this->v4)
      return true;
    if (i.v6 == this->v6) {
      uint64_t i64 = ((uint64_t) i.ipv6_address.s6_addr32[0] << 32) |
                     ((uint64_t) i.ipv6_address.s6_addr32[1]);
      uint64_t this64 = ((uint64_t) this->ipv6_address.s6_addr32[0] << 32) |
                        ((uint64_t) this->ipv6_address.s6_addr32[1]);

      if (i64 < this64)
        return true;
      else if (i64 > this64)
        return false;
      i64 = ((uint64_t) i.ipv6_address.s6_addr32[2] << 32) |
            ((uint64_t) i.ipv6_address.s6_addr32[3]);
      this64 = ((uint64_t) this->ipv6_address.s6_addr32[2] << 32) |
               ((uint64_t) this->ipv6_address.s6_addr32[3]);
      if (i64 < this64)
        return true;
      else if (i64 > this64)
        return false;
    } else if (this->v6)
      return true;
    return false;
  };
} fseid_t;



}


class CNRecord {
 public:
  CNRecord();
  virtual ~CNRecord();

  /////////////////////////////////////////////
  /// CNRecord members

  void merge(const EventNotification& event_data);
  void mergeAccessTypeChange(const EventNotification& event_data);
  void mergeUpPathChange(const EventNotification& event_data);
  void mergePDUSessRelease(const EventNotification& event_data);
  void mergePLMNChange(const EventNotification& event_data);
  void mergeUEIPChange(const EventNotification& event_data);
  void mergeDDDS(const EventNotification& event_data);

  /// <summary>
  ///
  /// </summary>
  SmfEvent getEvent() const;
  void setEvent(SmfEvent const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getTimeStamp() const;
  void setTimeStamp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getSupi() const;
  void setSupi(std::string const& value);
  bool supiIsSet() const;
  void unsetSupi();
  /// <summary>
  ///
  /// </summary>
  std::string getGpsi() const;
  void setGpsi(std::string const& value);
  bool gpsiIsSet() const;
  void unsetGpsi();
  /// <summary>
  ///
  /// </summary>
  std::string getSourceDnai() const;
  void setSourceDnai(std::string const& value);
  bool sourceDnaiIsSet() const;
  void unsetSourceDnai();
  /// <summary>
  ///
  /// </summary>
  std::string getTargetDnai() const;
  void setTargetDnai(std::string const& value);
  bool targetDnaiIsSet() const;
  void unsetTargetDnai();
  /// <summary>
  ///
  /// <summary>
  ///
  /// </summary>
  std::string getSourceUeIpv4Addr() const;
  void setSourceUeIpv4Addr(std::string const& value);
  bool sourceUeIpv4AddrIsSet() const;
  void unsetSourceUeIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  Ipv6Prefix getSourceUeIpv6Prefix() const;
  void setSourceUeIpv6Prefix(Ipv6Prefix const& value);
  bool sourceUeIpv6PrefixIsSet() const;
  void unsetSourceUeIpv6Prefix();
  /// <summary>
  ///
  /// </summary>
  std::string getTargetUeIpv4Addr() const;
  void setTargetUeIpv4Addr(std::string const& value);
  bool targetUeIpv4AddrIsSet() const;
  void unsetTargetUeIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  Ipv6Prefix getTargetUeIpv6Prefix() const;
  void setTargetUeIpv6Prefix(Ipv6Prefix const& value);
  bool targetUeIpv6PrefixIsSet() const;
  void unsetTargetUeIpv6Prefix();
  /// <summary>
  ///
  /// </summary>
  RouteToLocation getTargetTraRouting() const;
  void setTargetTraRouting(RouteToLocation const& value);
  bool targetTraRoutingIsSet() const;
  void unsetTargetTraRouting();
  /// <summary>
  ///
  /// </summary>
  std::string getUeMac() const;
  void setUeMac(std::string const& value);
  bool ueMacIsSet() const;
  void unsetUeMac();
  /// <summary>
  ///
  /// </summary>
  std::string getAdIpv4Addr() const;
  void setAdIpv4Addr(std::string const& value);
  bool adIpv4AddrIsSet() const;
  void unsetAdIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  Ipv6Prefix getAdIpv6Prefix() const;
  void setAdIpv6Prefix(Ipv6Prefix const& value);
  bool adIpv6PrefixIsSet() const;
  void unsetAdIpv6Prefix();
  /// <summary>
  ///
  /// </summary>
  Ipv6Prefix getReIpv6Prefix() const;
  void setReIpv6Prefix(Ipv6Prefix const& value);
  bool reIpv6PrefixIsSet() const;
  void unsetReIpv6Prefix();
  /// <summary>
  ///
  /// </summary>
  PlmnId getPlmnId() const;
  void setPlmnId(PlmnId const& value);
  bool plmnIdIsSet() const;
  void unsetPlmnId();
  /// <summary>
  ///
  /// </summary>
  DddStatus getDddStatus() const;
  void setDddStatus(DddStatus const& value);
  bool dddStatusIsSet() const;
  void unsetDddStatus();

  /// <summary>
  ///
  /// </summary>
  std::string getMaxWaitTime() const;
  void setMaxWaitTime(std::string const& value);
  bool maxWaitTimeIsSet() const;
  void unsetMaxWaitTime();

  // ===========================
  // Hung_TODO: extra fields that are important
  
  std::string getDnn() const;
  void setDnn(std::string const& value);
  bool dnnIsSet() const;
  void unsetDnn();

  std::string getAmfStatusUri() const;
  void setAmfStatusUri(std::string const& value);
  bool amfStatusUriIsSet() const;
  void unsetAmfStatusUri();

  // done

  // amf_addr
  std::string getAmfAddr() const;
  void setAmfAddr(std::string const& value);
  bool amfAddrIsSet() const;
  void unsetAmfAddr();

  // upf_node_id
  pfcp::node_id_t getUPFNodeId() const;
  void setUPFNodeId(pfcp::node_id_t const& value);
  bool upfNodeIdIsSet() const;
  void unsetUPFNodeId();

  // pdu_session_type_t getPduSeType() const;
  // void setPduSeType(pdu_session_type_t const& value);

  std::string getPduSeType() const;
  void setPduSeType(std::string const& value);
  bool pduSeTypeIsSet() const;
  void unsetPduSeType();

  // seid, 
  seid_t getSeid() const;
  void setSeid(seid_t const& value);
  bool seidIsSet() const;
  void unsetSeid();

  // up_fseid,
  pfcp::fseid_t getUpFseid() const;
  void setUpFseid(pfcp::fseid_t const& value);
  bool upFseidIsSet() const;
  void unsetUpFseid();

  // amf_id, 
  std::string getAmfId() const;
  void setAmfId(std::string const& value);
  bool amfIdIsSet() const;
  void unsetAmfId();

  //pduseid
  int32_t getPduSeId() const;
  void setPduSeId(int32_t const value);
  bool pduSeIdIsSet() const;
  void unsetPduSeId();

  // Dl_fteid [SMF]  
  pfcp::fteid_t getDlFteid() const;
  void setDlFteid(pfcp::fteid_t const& value);
  bool dlFteidIsSet() const;
  void unsetDlFteid();

  //Ul_fteid [SMF]
  pfcp::fteid_t getUlFteid() const;
  void setUlFteid(pfcp::fteid_t const& value);
  bool ulFteidIsSet() const;
  void unsetUlFteid();

  // eNB/gNB/CU IP@
  std::string getRanId() const;
  void setRanId(int32_t const value);
  bool ranIdIsSet() const;
  void unsetRanId();

  // custom: ue ip v4 
  std::string getUeIpv4() const;
  void setUeIpv4(std::string const value);
  bool ueIpv4IsSet() const;
  void unsetUeIpv4();

  // m_UeIpv6Prefix
  std::string getUeIpv6Prefix() const;
  void setUeIpv6Prefix(std::string const value);
  bool ueIpv6PrefixIsSet() const;
  void unsetUeIpv6Prefix();

  // snssai
  // std::string getSnssaiSst() const;
  int getSnssaiSst() const;
  std::string getSnssaiSd() const;
  // int getSnssaiSd() const;
  // void setSnssai(std::string const sst,std::string const sd);
  // void setSnssai(std::string const sst,int const sd);
    void setSnssai(int const sst,std::string const sd);

  bool snssaiIsSet() const;
  void unsetSnssai();

  // std::string m_snssai_sst;
  int m_snssai_sst;

  std::string m_snssai_sd;
  // int m_snssai_sd;
  bool m_snssaiIsSet;


  std::vector<qos_flow> getQosFlows() const;
  void setQosFlows(std::vector<qos_flow> const value);
  bool qosFlowsIsSet() const;
  void unsetQosFlows();

  bool customizedDataIsSet() const;

  // ===========================

  friend void to_json(nlohmann::json& j, const CNRecord& o);
  friend void from_json(const nlohmann::json& j, CNRecord& o);

 protected:
  std::vector<std::string> m_ListOptinalStringFields;
  SmfEvent m_Event;

  std::string m_TimeStamp;

  std::string m_Supi;
  bool m_SupiIsSet;
  std::string m_Gpsi;
  bool m_GpsiIsSet;
  std::string m_SourceDnai;
  bool m_SourceDnaiIsSet;
  std::string m_TargetDnai;
  bool m_TargetDnaiIsSet;
  std::string m_SourceUeIpv4Addr;
  bool m_SourceUeIpv4AddrIsSet;
  Ipv6Prefix m_SourceUeIpv6Prefix;
  bool m_SourceUeIpv6PrefixIsSet;
  std::string m_TargetUeIpv4Addr;
  bool m_TargetUeIpv4AddrIsSet;
  Ipv6Prefix m_TargetUeIpv6Prefix;
  bool m_TargetUeIpv6PrefixIsSet;
  RouteToLocation m_TargetTraRouting;
  bool m_TargetTraRoutingIsSet;
  std::string m_UeMac;
  bool m_UeMacIsSet;
  std::string m_AdIpv4Addr;
  bool m_AdIpv4AddrIsSet;
  Ipv6Prefix m_AdIpv6Prefix;
  bool m_AdIpv6PrefixIsSet;
  Ipv6Prefix m_ReIpv6Prefix;
  bool m_ReIpv6PrefixIsSet;
  PlmnId m_PlmnId;
  bool m_PlmnIdIsSet;
  DddStatus m_DddStatus;
  bool m_DddStatusIsSet;
  std::string m_MaxWaitTime;
  bool m_MaxWaitTimeIsSet;
  int32_t m_PduSeId;
  bool m_PduSeIdIsSet;

  // ===========================
  // Hung_TODO: extra fields that are important

  bool m_CustomizedDataIsSet;

  std::string m_Dnn;
  bool m_DnnIsSet;
  
  std::string m_AmfStatusUri;
  bool m_AmfStatusUriIsSet;

  std::string m_AmfAddr;
  bool m_AmfAddrIsSet;

  // TODO: clean?? 
  pfcp::node_id_t m_UpfNodeId;
  bool m_UpfNodeIdIsSet;

  std::string m_PduSeType;
  bool m_PduSeTypeIsSet;
  
  // seid,
  seid_t m_seid;
  bool m_seidIsSet;

  // up_fseid,
  pfcp::fseid_t m_UpFseid;
  bool m_UpFseidIsSet;

  // amf_id, 
  std::string m_AmfId;
  bool m_AmfIdIsSet;

  // Dl_fteid [SMF]  
  pfcp::fteid_t m_DlFteid;
  bool m_DlFteidIsSet;

  //Ul_fteid [SMF]
  pfcp::fteid_t m_UlFteid;
  bool m_UlFteidIsSet;

  // eNB/gNB/CU IP@
  std::string m_RanIP;
  bool m_RanIPIsSet;

  //ueipv4
  std::string m_UeIpv4;
  bool m_UeIpv4IsSet;

  //ue_ipv6_prefix
  std::string m_UeIpv6Prefix;
  bool m_UeIpv6PrefixIsSet;

  std::vector<qos_flow> m_QosFlows;
  bool m_QosFlowsIsSet;

 //Hung_TODO: flow id and QFI is this the same
  // ===========================
};


}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* FILE_FLEXCN_APP_HPP_SEEN */