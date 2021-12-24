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
 * AdditionalQosFlowInfo.h
 *
 *
 */

#ifndef AdditionalQosFlowInfo_H_
#define AdditionalQosFlowInfo_H_

#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class AdditionalQosFlowInfo {
 public:
  AdditionalQosFlowInfo();
  virtual ~AdditionalQosFlowInfo();

  void validate();

  /////////////////////////////////////////////
  /// AdditionalQosFlowInfo members

  friend void to_json(nlohmann::json& j, const AdditionalQosFlowInfo& o);
  friend void from_json(const nlohmann::json& j, AdditionalQosFlowInfo& o);

 protected:
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* AdditionalQosFlowInfo_H_ */