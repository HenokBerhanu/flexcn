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
 * Cause.h
 *
 * Possible values are - REL_DUE_TO_HO - EPS_FALLBACK - REL_DUE_TO_UP_SEC -
 * DNN_CONGESTION - S_NSSAI_CONGESTION - REL_DUE_TO_REACTIVATION -
 * 5G_AN_NOT_RESPONDING - REL_DUE_TO_SLICE_NOT_AVAILABLE -
 * REL_DUE_TO_DUPLICATE_SESSION_ID - PDU_SESSION_STATUS_MISMATCH - HO_FAILURE -
 * INSUFFICIENT_UP_RESOURCES - PDU_SESSION_HANDED_OVER
 */

#ifndef Cause_H_
#define Cause_H_

#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
/// Possible values are - REL_DUE_TO_HO - EPS_FALLBACK - REL_DUE_TO_UP_SEC -
/// DNN_CONGESTION - S_NSSAI_CONGESTION - REL_DUE_TO_REACTIVATION -
/// 5G_AN_NOT_RESPONDING - REL_DUE_TO_SLICE_NOT_AVAILABLE -
/// REL_DUE_TO_DUPLICATE_SESSION_ID - PDU_SESSION_STATUS_MISMATCH - HO_FAILURE -
/// INSUFFICIENT_UP_RESOURCES - PDU_SESSION_HANDED_OVER
/// </summary>
class Cause {
 public:
  Cause();
  virtual ~Cause();

  void validate();

  /////////////////////////////////////////////
  /// Cause members

  friend void to_json(nlohmann::json& j, const Cause& o);
  friend void from_json(const nlohmann::json& j, Cause& o);

 protected:
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* Cause_H_ */
