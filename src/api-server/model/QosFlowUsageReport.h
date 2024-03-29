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
/*
 * QosFlowUsageReport.h
 *
 *
 */

#ifndef QosFlowUsageReport_H_
#define QosFlowUsageReport_H_

#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class QosFlowUsageReport {
 public:
  QosFlowUsageReport();
  virtual ~QosFlowUsageReport();

  void validate();

  /////////////////////////////////////////////
  /// QosFlowUsageReport members

  /// <summary>
  ///
  /// </summary>
  int32_t getQfi() const;
  void setQfi(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getStartTimeStamp() const;
  void setStartTimeStamp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getEndTimeStamp() const;
  void setEndTimeStamp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  int64_t getDownlinkVolume() const;
  void setDownlinkVolume(int64_t const value);
  /// <summary>
  ///
  /// </summary>
  int64_t getUplinkVolume() const;
  void setUplinkVolume(int64_t const value);

  friend void to_json(nlohmann::json& j, const QosFlowUsageReport& o);
  friend void from_json(const nlohmann::json& j, QosFlowUsageReport& o);

 protected:
  int32_t m_Qfi;

  std::string m_StartTimeStamp;

  std::string m_EndTimeStamp;

  int64_t m_DownlinkVolume;

  int64_t m_UplinkVolume;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* QosFlowUsageReport_H_ */
