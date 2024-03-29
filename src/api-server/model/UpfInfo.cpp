/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "UpfInfo.h"

namespace oai {
namespace flexcn_server {
namespace model {

UpfInfo::UpfInfo() {
  m_SmfServingAreaIsSet       = false;
  m_InterfaceUpfInfoListIsSet = false;
  m_IwkEpsInd                 = false;
  m_IwkEpsIndIsSet            = false;
  m_PduSessionTypesIsSet      = false;
  m_AtsssCapabilityIsSet      = false;
  m_UeIpAddrInd               = false;
  m_UeIpAddrIndIsSet          = false;
}

UpfInfo::~UpfInfo() {}

void UpfInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const UpfInfo& o) {
  j                      = nlohmann::json();
  j["sNssaiUpfInfoList"] = o.m_SNssaiUpfInfoList;
  if (o.smfServingAreaIsSet() || !o.m_SmfServingArea.empty())
    j["smfServingArea"] = o.m_SmfServingArea;
  if (o.interfaceUpfInfoListIsSet() || !o.m_InterfaceUpfInfoList.empty())
    j["interfaceUpfInfoList"] = o.m_InterfaceUpfInfoList;
  if (o.iwkEpsIndIsSet()) j["iwkEpsInd"] = o.m_IwkEpsInd;
  if (o.pduSessionTypesIsSet() || !o.m_PduSessionTypes.empty())
    j["pduSessionTypes"] = o.m_PduSessionTypes;
  if (o.atsssCapabilityIsSet()) j["atsssCapability"] = o.m_AtsssCapability;
  if (o.ueIpAddrIndIsSet()) j["ueIpAddrInd"] = o.m_UeIpAddrInd;
}

void from_json(const nlohmann::json& j, UpfInfo& o) {
  j.at("sNssaiUpfInfoList").get_to(o.m_SNssaiUpfInfoList);
  if (j.find("smfServingArea") != j.end()) {
    j.at("smfServingArea").get_to(o.m_SmfServingArea);
    o.m_SmfServingAreaIsSet = true;
  }
  if (j.find("interfaceUpfInfoList") != j.end()) {
    j.at("interfaceUpfInfoList").get_to(o.m_InterfaceUpfInfoList);
    o.m_InterfaceUpfInfoListIsSet = true;
  }
  if (j.find("iwkEpsInd") != j.end()) {
    j.at("iwkEpsInd").get_to(o.m_IwkEpsInd);
    o.m_IwkEpsIndIsSet = true;
  }
  if (j.find("pduSessionTypes") != j.end()) {
    j.at("pduSessionTypes").get_to(o.m_PduSessionTypes);
    o.m_PduSessionTypesIsSet = true;
  }
  if (j.find("atsssCapability") != j.end()) {
    j.at("atsssCapability").get_to(o.m_AtsssCapability);
    o.m_AtsssCapabilityIsSet = true;
  }
  if (j.find("ueIpAddrInd") != j.end()) {
    j.at("ueIpAddrInd").get_to(o.m_UeIpAddrInd);
    o.m_UeIpAddrIndIsSet = true;
  }
}

std::vector<SnssaiUpfInfoItem>& UpfInfo::getSNssaiUpfInfoList() {
  return m_SNssaiUpfInfoList;
}
void UpfInfo::setSNssaiUpfInfoList(
    std::vector<SnssaiUpfInfoItem> const& value) {
  m_SNssaiUpfInfoList = value;
}
std::vector<std::string>& UpfInfo::getSmfServingArea() {
  return m_SmfServingArea;
}
void UpfInfo::setSmfServingArea(std::vector<std::string> const& value) {
  m_SmfServingArea      = value;
  m_SmfServingAreaIsSet = true;
}
bool UpfInfo::smfServingAreaIsSet() const {
  return m_SmfServingAreaIsSet;
}
void UpfInfo::unsetSmfServingArea() {
  m_SmfServingAreaIsSet = false;
}
std::vector<InterfaceUpfInfoItem>& UpfInfo::getInterfaceUpfInfoList() {
  return m_InterfaceUpfInfoList;
}
void UpfInfo::setInterfaceUpfInfoList(
    std::vector<InterfaceUpfInfoItem> const& value) {
  m_InterfaceUpfInfoList      = value;
  m_InterfaceUpfInfoListIsSet = true;
}
bool UpfInfo::interfaceUpfInfoListIsSet() const {
  return m_InterfaceUpfInfoListIsSet;
}
void UpfInfo::unsetInterfaceUpfInfoList() {
  m_InterfaceUpfInfoListIsSet = false;
}
bool UpfInfo::isIwkEpsInd() const {
  return m_IwkEpsInd;
}
void UpfInfo::setIwkEpsInd(bool const value) {
  m_IwkEpsInd      = value;
  m_IwkEpsIndIsSet = true;
}
bool UpfInfo::iwkEpsIndIsSet() const {
  return m_IwkEpsIndIsSet;
}
void UpfInfo::unsetIwkEpsInd() {
  m_IwkEpsIndIsSet = false;
}
std::vector<PduSessionType>& UpfInfo::getPduSessionTypes() {
  return m_PduSessionTypes;
}
void UpfInfo::setPduSessionTypes(std::vector<PduSessionType> const& value) {
  m_PduSessionTypes      = value;
  m_PduSessionTypesIsSet = true;
}
bool UpfInfo::pduSessionTypesIsSet() const {
  return m_PduSessionTypesIsSet;
}
void UpfInfo::unsetPduSessionTypes() {
  m_PduSessionTypesIsSet = false;
}
AtsssCapability UpfInfo::getAtsssCapability() const {
  return m_AtsssCapability;
}
void UpfInfo::setAtsssCapability(AtsssCapability const& value) {
  m_AtsssCapability      = value;
  m_AtsssCapabilityIsSet = true;
}
bool UpfInfo::atsssCapabilityIsSet() const {
  return m_AtsssCapabilityIsSet;
}
void UpfInfo::unsetAtsssCapability() {
  m_AtsssCapabilityIsSet = false;
}
bool UpfInfo::isUeIpAddrInd() const {
  return m_UeIpAddrInd;
}
void UpfInfo::setUeIpAddrInd(bool const value) {
  m_UeIpAddrInd      = value;
  m_UeIpAddrIndIsSet = true;
}
bool UpfInfo::ueIpAddrIndIsSet() const {
  return m_UeIpAddrIndIsSet;
}
void UpfInfo::unsetUeIpAddrInd() {
  m_UeIpAddrIndIsSet = false;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
