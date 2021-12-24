/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "SmContextUpdateError.h"

namespace oai {
namespace flexcn_server {
namespace model {

SmContextUpdateError::SmContextUpdateError() {
  m_N1SmMsgIsSet      = false;
  m_N2SmInfoIsSet     = false;
  m_N2SmInfoTypeIsSet = false;
  m_UpCnxStateIsSet   = false;
  m_RecoveryTime      = "";
  m_RecoveryTimeIsSet = false;
}

SmContextUpdateError::~SmContextUpdateError() {}

void SmContextUpdateError::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const SmContextUpdateError& o) {
  j          = nlohmann::json();
  j["error"] = o.m_Error;
  if (o.n1SmMsgIsSet()) j["n1SmMsg"] = o.m_N1SmMsg;
  if (o.n2SmInfoIsSet()) j["n2SmInfo"] = o.m_N2SmInfo;
  if (o.n2SmInfoTypeIsSet()) j["n2SmInfoType"] = o.m_N2SmInfoType;
  if (o.upCnxStateIsSet()) j["upCnxState"] = o.m_UpCnxState;
  if (o.recoveryTimeIsSet()) j["recoveryTime"] = o.m_RecoveryTime;
}

void from_json(const nlohmann::json& j, SmContextUpdateError& o) {
  j.at("error").get_to(o.m_Error);
  if (j.find("n1SmMsg") != j.end()) {
    j.at("n1SmMsg").get_to(o.m_N1SmMsg);
    o.m_N1SmMsgIsSet = true;
  }
  if (j.find("n2SmInfo") != j.end()) {
    j.at("n2SmInfo").get_to(o.m_N2SmInfo);
    o.m_N2SmInfoIsSet = true;
  }
  if (j.find("n2SmInfoType") != j.end()) {
    j.at("n2SmInfoType").get_to(o.m_N2SmInfoType);
    o.m_N2SmInfoTypeIsSet = true;
  }
  if (j.find("upCnxState") != j.end()) {
    j.at("upCnxState").get_to(o.m_UpCnxState);
    o.m_UpCnxStateIsSet = true;
  }
  if (j.find("recoveryTime") != j.end()) {
    j.at("recoveryTime").get_to(o.m_RecoveryTime);
    o.m_RecoveryTimeIsSet = true;
  }
}

ProblemDetails SmContextUpdateError::getError() const {
  return m_Error;
}
void SmContextUpdateError::setError(ProblemDetails const& value) {
  m_Error = value;
}
RefToBinaryData SmContextUpdateError::getN1SmMsg() const {
  return m_N1SmMsg;
}
void SmContextUpdateError::setN1SmMsg(RefToBinaryData const& value) {
  m_N1SmMsg      = value;
  m_N1SmMsgIsSet = true;
}
bool SmContextUpdateError::n1SmMsgIsSet() const {
  return m_N1SmMsgIsSet;
}
void SmContextUpdateError::unsetN1SmMsg() {
  m_N1SmMsgIsSet = false;
}
RefToBinaryData SmContextUpdateError::getN2SmInfo() const {
  return m_N2SmInfo;
}
void SmContextUpdateError::setN2SmInfo(RefToBinaryData const& value) {
  m_N2SmInfo      = value;
  m_N2SmInfoIsSet = true;
}
bool SmContextUpdateError::n2SmInfoIsSet() const {
  return m_N2SmInfoIsSet;
}
void SmContextUpdateError::unsetN2SmInfo() {
  m_N2SmInfoIsSet = false;
}
N2SmInfoType SmContextUpdateError::getN2SmInfoType() const {
  return m_N2SmInfoType;
}
void SmContextUpdateError::setN2SmInfoType(N2SmInfoType const& value) {
  m_N2SmInfoType      = value;
  m_N2SmInfoTypeIsSet = true;
}
bool SmContextUpdateError::n2SmInfoTypeIsSet() const {
  return m_N2SmInfoTypeIsSet;
}
void SmContextUpdateError::unsetN2SmInfoType() {
  m_N2SmInfoTypeIsSet = false;
}
UpCnxState SmContextUpdateError::getUpCnxState() const {
  return m_UpCnxState;
}
void SmContextUpdateError::setUpCnxState(UpCnxState const& value) {
  m_UpCnxState      = value;
  m_UpCnxStateIsSet = true;
}
bool SmContextUpdateError::upCnxStateIsSet() const {
  return m_UpCnxStateIsSet;
}
void SmContextUpdateError::unsetUpCnxState() {
  m_UpCnxStateIsSet = false;
}
std::string SmContextUpdateError::getRecoveryTime() const {
  return m_RecoveryTime;
}
void SmContextUpdateError::setRecoveryTime(std::string const& value) {
  m_RecoveryTime      = value;
  m_RecoveryTimeIsSet = true;
}
bool SmContextUpdateError::recoveryTimeIsSet() const {
  return m_RecoveryTimeIsSet;
}
void SmContextUpdateError::unsetRecoveryTime() {
  m_RecoveryTimeIsSet = false;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
