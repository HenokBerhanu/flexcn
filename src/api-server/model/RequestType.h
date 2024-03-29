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
 * RequestType.h
 *
 * Possible values are - INITIAL_REQUEST - EXISTING_PDU_SESSION -
 * INITIAL_EMERGENCY_REQUEST - EXISTING_EMERGENCY_PDU_SESSION
 */

#ifndef RequestType_H_
#define RequestType_H_

#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
/// Possible values are - INITIAL_REQUEST - EXISTING_PDU_SESSION -
/// INITIAL_EMERGENCY_REQUEST - EXISTING_EMERGENCY_PDU_SESSION
/// </summary>
class RequestType {
 public:
  RequestType();
  virtual ~RequestType();

  void validate();

  /////////////////////////////////////////////
  /// RequestType members

  friend void to_json(nlohmann::json& j, const RequestType& o);
  friend void from_json(const nlohmann::json& j, RequestType& o);

 protected:
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* RequestType_H_ */
