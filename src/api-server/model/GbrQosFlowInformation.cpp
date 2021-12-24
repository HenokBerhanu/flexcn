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

#include "GbrQosFlowInformation.h"

namespace oai {
namespace flexcn_server {
namespace model {

GbrQosFlowInformation::GbrQosFlowInformation() {
  m_MaxFbrDl                 = "";
  m_MaxFbrUl                 = "";
  m_GuaFbrDl                 = "";
  m_GuaFbrUl                 = "";
  m_NotifControlIsSet        = false;
  m_MaxPacketLossRateDl      = 0;
  m_MaxPacketLossRateDlIsSet = false;
  m_MaxPacketLossRateUl      = 0;
  m_MaxPacketLossRateUlIsSet = false;
}

GbrQosFlowInformation::~GbrQosFlowInformation() {}

void GbrQosFlowInformation::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const GbrQosFlowInformation& o) {
  j             = nlohmann::json();
  j["maxFbrDl"] = o.m_MaxFbrDl;
  j["maxFbrUl"] = o.m_MaxFbrUl;
  j["guaFbrDl"] = o.m_GuaFbrDl;
  j["guaFbrUl"] = o.m_GuaFbrUl;
  if (o.notifControlIsSet()) j["notifControl"] = o.m_NotifControl;
  if (o.maxPacketLossRateDlIsSet())
    j["maxPacketLossRateDl"] = o.m_MaxPacketLossRateDl;
  if (o.maxPacketLossRateUlIsSet())
    j["maxPacketLossRateUl"] = o.m_MaxPacketLossRateUl;
}

void from_json(const nlohmann::json& j, GbrQosFlowInformation& o) {
  j.at("maxFbrDl").get_to(o.m_MaxFbrDl);
  j.at("maxFbrUl").get_to(o.m_MaxFbrUl);
  j.at("guaFbrDl").get_to(o.m_GuaFbrDl);
  j.at("guaFbrUl").get_to(o.m_GuaFbrUl);
  if (j.find("notifControl") != j.end()) {
    j.at("notifControl").get_to(o.m_NotifControl);
    o.m_NotifControlIsSet = true;
  }
  if (j.find("maxPacketLossRateDl") != j.end()) {
    j.at("maxPacketLossRateDl").get_to(o.m_MaxPacketLossRateDl);
    o.m_MaxPacketLossRateDlIsSet = true;
  }
  if (j.find("maxPacketLossRateUl") != j.end()) {
    j.at("maxPacketLossRateUl").get_to(o.m_MaxPacketLossRateUl);
    o.m_MaxPacketLossRateUlIsSet = true;
  }
}

std::string GbrQosFlowInformation::getMaxFbrDl() const {
  return m_MaxFbrDl;
}
void GbrQosFlowInformation::setMaxFbrDl(std::string const& value) {
  m_MaxFbrDl = value;
}
std::string GbrQosFlowInformation::getMaxFbrUl() const {
  return m_MaxFbrUl;
}
void GbrQosFlowInformation::setMaxFbrUl(std::string const& value) {
  m_MaxFbrUl = value;
}
std::string GbrQosFlowInformation::getGuaFbrDl() const {
  return m_GuaFbrDl;
}
void GbrQosFlowInformation::setGuaFbrDl(std::string const& value) {
  m_GuaFbrDl = value;
}
std::string GbrQosFlowInformation::getGuaFbrUl() const {
  return m_GuaFbrUl;
}
void GbrQosFlowInformation::setGuaFbrUl(std::string const& value) {
  m_GuaFbrUl = value;
}
NotificationControl GbrQosFlowInformation::getNotifControl() const {
  return m_NotifControl;
}
void GbrQosFlowInformation::setNotifControl(NotificationControl const& value) {
  m_NotifControl      = value;
  m_NotifControlIsSet = true;
}
bool GbrQosFlowInformation::notifControlIsSet() const {
  return m_NotifControlIsSet;
}
void GbrQosFlowInformation::unsetNotifControl() {
  m_NotifControlIsSet = false;
}
int32_t GbrQosFlowInformation::getMaxPacketLossRateDl() const {
  return m_MaxPacketLossRateDl;
}
void GbrQosFlowInformation::setMaxPacketLossRateDl(int32_t const value) {
  m_MaxPacketLossRateDl      = value;
  m_MaxPacketLossRateDlIsSet = true;
}
bool GbrQosFlowInformation::maxPacketLossRateDlIsSet() const {
  return m_MaxPacketLossRateDlIsSet;
}
void GbrQosFlowInformation::unsetMaxPacketLossRateDl() {
  m_MaxPacketLossRateDlIsSet = false;
}
int32_t GbrQosFlowInformation::getMaxPacketLossRateUl() const {
  return m_MaxPacketLossRateUl;
}
void GbrQosFlowInformation::setMaxPacketLossRateUl(int32_t const value) {
  m_MaxPacketLossRateUl      = value;
  m_MaxPacketLossRateUlIsSet = true;
}
bool GbrQosFlowInformation::maxPacketLossRateUlIsSet() const {
  return m_MaxPacketLossRateUlIsSet;
}
void GbrQosFlowInformation::unsetMaxPacketLossRateUl() {
  m_MaxPacketLossRateUlIsSet = false;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
