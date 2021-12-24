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

#include "PlmnId.h"

namespace oai {
namespace flexcn_server {
namespace model {

PlmnId::PlmnId() {
  m_Mcc = "";
  m_Mnc = "";
}

PlmnId::~PlmnId() {}

void PlmnId::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const PlmnId& o) {
  j        = nlohmann::json();
  j["mcc"] = o.m_Mcc;
  j["mnc"] = o.m_Mnc;
}

void from_json(const nlohmann::json& j, PlmnId& o) {
  j.at("mcc").get_to(o.m_Mcc);
  j.at("mnc").get_to(o.m_Mnc);
}

std::string PlmnId::getMcc() const {
  return m_Mcc;
}
void PlmnId::setMcc(std::string const& value) {
  m_Mcc = value;
}
std::string PlmnId::getMnc() const {
  return m_Mnc;
}
void PlmnId::setMnc(std::string const& value) {
  m_Mnc = value;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
