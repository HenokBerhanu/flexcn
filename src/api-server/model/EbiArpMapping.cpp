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

#include "EbiArpMapping.h"

namespace oai {
namespace flexcn_server {
namespace model {

EbiArpMapping::EbiArpMapping() {
  m_EpsBearerId = 0;
}

EbiArpMapping::~EbiArpMapping() {}

void EbiArpMapping::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const EbiArpMapping& o) {
  j                = nlohmann::json();
  j["epsBearerId"] = o.m_EpsBearerId;
  j["arp"]         = o.m_Arp;
}

void from_json(const nlohmann::json& j, EbiArpMapping& o) {
  j.at("epsBearerId").get_to(o.m_EpsBearerId);
  j.at("arp").get_to(o.m_Arp);
}

int32_t EbiArpMapping::getEpsBearerId() const {
  return m_EpsBearerId;
}
void EbiArpMapping::setEpsBearerId(int32_t const value) {
  m_EpsBearerId = value;
}
Arp EbiArpMapping::getArp() const {
  return m_Arp;
}
void EbiArpMapping::setArp(Arp const& value) {
  m_Arp = value;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
