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

#include "N3gaLocation.h"

namespace oai {
namespace flexcn_server {
namespace model {

N3gaLocation::N3gaLocation() {
  m_N3gppTaiIsSet   = false;
  m_N3IwfId         = "";
  m_N3IwfIdIsSet    = false;
  m_UeIpv4Addr      = "";
  m_UeIpv4AddrIsSet = false;
  m_UeIpv6AddrIsSet = false;
  m_PortNumber      = 0;
  m_PortNumberIsSet = false;
}

N3gaLocation::~N3gaLocation() {}

void N3gaLocation::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const N3gaLocation& o) {
  j = nlohmann::json();
  if (o.n3gppTaiIsSet()) j["n3gppTai"] = o.m_N3gppTai;
  if (o.n3IwfIdIsSet()) j["n3IwfId"] = o.m_N3IwfId;
  if (o.ueIpv4AddrIsSet()) j["ueIpv4Addr"] = o.m_UeIpv4Addr;
  if (o.ueIpv6AddrIsSet()) j["ueIpv6Addr"] = o.m_UeIpv6Addr;
  if (o.portNumberIsSet()) j["portNumber"] = o.m_PortNumber;
}

void from_json(const nlohmann::json& j, N3gaLocation& o) {
  if (j.find("n3gppTai") != j.end()) {
    j.at("n3gppTai").get_to(o.m_N3gppTai);
    o.m_N3gppTaiIsSet = true;
  }
  if (j.find("n3IwfId") != j.end()) {
    j.at("n3IwfId").get_to(o.m_N3IwfId);
    o.m_N3IwfIdIsSet = true;
  }
  if (j.find("ueIpv4Addr") != j.end()) {
    j.at("ueIpv4Addr").get_to(o.m_UeIpv4Addr);
    o.m_UeIpv4AddrIsSet = true;
  }
  if (j.find("ueIpv6Addr") != j.end()) {
    j.at("ueIpv6Addr").get_to(o.m_UeIpv6Addr);
    o.m_UeIpv6AddrIsSet = true;
  }
  if (j.find("portNumber") != j.end()) {
    j.at("portNumber").get_to(o.m_PortNumber);
    o.m_PortNumberIsSet = true;
  }
}

Tai N3gaLocation::getN3gppTai() const {
  return m_N3gppTai;
}
void N3gaLocation::setN3gppTai(Tai const& value) {
  m_N3gppTai      = value;
  m_N3gppTaiIsSet = true;
}
bool N3gaLocation::n3gppTaiIsSet() const {
  return m_N3gppTaiIsSet;
}
void N3gaLocation::unsetN3gppTai() {
  m_N3gppTaiIsSet = false;
}
std::string N3gaLocation::getN3IwfId() const {
  return m_N3IwfId;
}
void N3gaLocation::setN3IwfId(std::string const& value) {
  m_N3IwfId      = value;
  m_N3IwfIdIsSet = true;
}
bool N3gaLocation::n3IwfIdIsSet() const {
  return m_N3IwfIdIsSet;
}
void N3gaLocation::unsetN3IwfId() {
  m_N3IwfIdIsSet = false;
}
std::string N3gaLocation::getUeIpv4Addr() const {
  return m_UeIpv4Addr;
}
void N3gaLocation::setUeIpv4Addr(std::string const& value) {
  m_UeIpv4Addr      = value;
  m_UeIpv4AddrIsSet = true;
}
bool N3gaLocation::ueIpv4AddrIsSet() const {
  return m_UeIpv4AddrIsSet;
}
void N3gaLocation::unsetUeIpv4Addr() {
  m_UeIpv4AddrIsSet = false;
}
std::string N3gaLocation::getUeIpv6Addr() const {
  return m_UeIpv6Addr;
}
void N3gaLocation::setUeIpv6Addr(std::string const& value) {
  m_UeIpv6Addr      = value;
  m_UeIpv6AddrIsSet = true;
}
bool N3gaLocation::ueIpv6AddrIsSet() const {
  return m_UeIpv6AddrIsSet;
}
void N3gaLocation::unsetUeIpv6Addr() {
  m_UeIpv6AddrIsSet = false;
}
int32_t N3gaLocation::getPortNumber() const {
  return m_PortNumber;
}
void N3gaLocation::setPortNumber(int32_t const value) {
  m_PortNumber      = value;
  m_PortNumberIsSet = true;
}
bool N3gaLocation::portNumberIsSet() const {
  return m_PortNumberIsSet;
}
void N3gaLocation::unsetPortNumber() {
  m_PortNumberIsSet = false;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
