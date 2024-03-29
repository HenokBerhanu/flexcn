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

#include "VolumeTimedReport.h"

namespace oai {
namespace flexcn_server {
namespace model {

VolumeTimedReport::VolumeTimedReport() {
  m_StartTimeStamp = "";
  m_EndTimeStamp   = "";
  m_DownlinkVolume = 0L;
  m_UplinkVolume   = 0L;
}

VolumeTimedReport::~VolumeTimedReport() {}

void VolumeTimedReport::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const VolumeTimedReport& o) {
  j                   = nlohmann::json();
  j["startTimeStamp"] = o.m_StartTimeStamp;
  j["endTimeStamp"]   = o.m_EndTimeStamp;
  j["downlinkVolume"] = o.m_DownlinkVolume;
  j["uplinkVolume"]   = o.m_UplinkVolume;
}

void from_json(const nlohmann::json& j, VolumeTimedReport& o) {
  j.at("startTimeStamp").get_to(o.m_StartTimeStamp);
  j.at("endTimeStamp").get_to(o.m_EndTimeStamp);
  j.at("downlinkVolume").get_to(o.m_DownlinkVolume);
  j.at("uplinkVolume").get_to(o.m_UplinkVolume);
}

std::string VolumeTimedReport::getStartTimeStamp() const {
  return m_StartTimeStamp;
}
void VolumeTimedReport::setStartTimeStamp(std::string const& value) {
  m_StartTimeStamp = value;
}
std::string VolumeTimedReport::getEndTimeStamp() const {
  return m_EndTimeStamp;
}
void VolumeTimedReport::setEndTimeStamp(std::string const& value) {
  m_EndTimeStamp = value;
}
int64_t VolumeTimedReport::getDownlinkVolume() const {
  return m_DownlinkVolume;
}
void VolumeTimedReport::setDownlinkVolume(int64_t const value) {
  m_DownlinkVolume = value;
}
int64_t VolumeTimedReport::getUplinkVolume() const {
  return m_UplinkVolume;
}
void VolumeTimedReport::setUplinkVolume(int64_t const value) {
  m_UplinkVolume = value;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
