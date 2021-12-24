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

#include "RoamingChargingProfile.h"

namespace oai {
namespace flexcn_server {
namespace model {

RoamingChargingProfile::RoamingChargingProfile() {
  m_TriggersIsSet            = false;
  m_PartialRecordMethodIsSet = false;
}

RoamingChargingProfile::~RoamingChargingProfile() {}

void RoamingChargingProfile::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const RoamingChargingProfile& o) {
  j = nlohmann::json();
  if (o.triggersIsSet()) j["triggers"] = o.m_Triggers;
  if (o.partialRecordMethodIsSet())
    j["partialRecordMethod"] = o.m_PartialRecordMethod;
}

void from_json(const nlohmann::json& j, RoamingChargingProfile& o) {
  if (j.find("triggers") != j.end()) {
    j.at("triggers").get_to(o.m_Triggers);
    o.m_TriggersIsSet = true;
  }
  if (j.find("partialRecordMethod") != j.end()) {
    j.at("partialRecordMethod").get_to(o.m_PartialRecordMethod);
    o.m_PartialRecordMethodIsSet = true;
  }
}

std::vector<Trigger>& RoamingChargingProfile::getTriggers() {
  return m_Triggers;
}
bool RoamingChargingProfile::triggersIsSet() const {
  return m_TriggersIsSet;
}
void RoamingChargingProfile::unsetTriggers() {
  m_TriggersIsSet = false;
}
PartialRecordMethod RoamingChargingProfile::getPartialRecordMethod() const {
  return m_PartialRecordMethod;
}
void RoamingChargingProfile::setPartialRecordMethod(
    PartialRecordMethod const& value) {
  m_PartialRecordMethod      = value;
  m_PartialRecordMethodIsSet = true;
}
bool RoamingChargingProfile::partialRecordMethodIsSet() const {
  return m_PartialRecordMethodIsSet;
}
void RoamingChargingProfile::unsetPartialRecordMethod() {
  m_PartialRecordMethodIsSet = false;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
