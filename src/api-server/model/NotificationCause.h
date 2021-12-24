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
 * NotificationCause.h
 *
 * Possible values are - QOS_FULFILLED - QOS_NOT_FULFILLED - UP_SEC_FULFILLED -
 * UP_SEC_NOT_FULFILLED
 */

#ifndef NotificationCause_H_
#define NotificationCause_H_

#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
/// Possible values are - QOS_FULFILLED - QOS_NOT_FULFILLED - UP_SEC_FULFILLED -
/// UP_SEC_NOT_FULFILLED
/// </summary>
class NotificationCause {
 public:
  NotificationCause();
  virtual ~NotificationCause();

  void validate();

  /////////////////////////////////////////////
  /// NotificationCause members

  friend void to_json(nlohmann::json& j, const NotificationCause& o);
  friend void from_json(const nlohmann::json& j, NotificationCause& o);

 protected:
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* NotificationCause_H_ */
