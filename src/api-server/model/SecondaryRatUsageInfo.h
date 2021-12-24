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
 * SecondaryRatUsageInfo.h
 *
 *
 */

#ifndef SecondaryRatUsageInfo_H_
#define SecondaryRatUsageInfo_H_

#include "VolumeTimedReport.h"
#include "QosFlowUsageReport.h"
#include "RatType.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class SecondaryRatUsageInfo {
 public:
  SecondaryRatUsageInfo();
  virtual ~SecondaryRatUsageInfo();

  void validate();

  /////////////////////////////////////////////
  /// SecondaryRatUsageInfo members

  /// <summary>
  ///
  /// </summary>
  RatType getSecondaryRatType() const;
  void setSecondaryRatType(RatType const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<QosFlowUsageReport>& getQosFlowsUsageData();
  bool qosFlowsUsageDataIsSet() const;
  void unsetQosFlowsUsageData();
  /// <summary>
  ///
  /// </summary>
  std::vector<VolumeTimedReport>& getPduSessionUsageData();
  bool pduSessionUsageDataIsSet() const;
  void unsetPduSessionUsageData();

  friend void to_json(nlohmann::json& j, const SecondaryRatUsageInfo& o);
  friend void from_json(const nlohmann::json& j, SecondaryRatUsageInfo& o);

 protected:
  RatType m_SecondaryRatType;

  std::vector<QosFlowUsageReport> m_QosFlowsUsageData;
  bool m_QosFlowsUsageDataIsSet;
  std::vector<VolumeTimedReport> m_PduSessionUsageData;
  bool m_PduSessionUsageDataIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* SecondaryRatUsageInfo_H_ */
