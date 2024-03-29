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

#include "Tai.h"

namespace oai {
namespace flexcn_server {
namespace model {

Tai::Tai() {
  m_Tac = "";
}

Tai::~Tai() {}

void Tai::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const Tai& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["tac"]    = o.m_Tac;
}

void from_json(const nlohmann::json& j, Tai& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("tac").get_to(o.m_Tac);
}

PlmnId Tai::getPlmnId() const {
  return m_PlmnId;
}
void Tai::setPlmnId(PlmnId const& value) {
  m_PlmnId = value;
}
std::string Tai::getTac() const {
  return m_Tac;
}
void Tai::setTac(std::string const& value) {
  m_Tac = value;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
