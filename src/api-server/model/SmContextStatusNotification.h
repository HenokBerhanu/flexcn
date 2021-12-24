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
 * SmContextStatusNotification.h
 *
 *
 */

#ifndef SmContextStatusNotification_H_
#define SmContextStatusNotification_H_

#include "StatusInfo.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class SmContextStatusNotification {
 public:
  SmContextStatusNotification();
  virtual ~SmContextStatusNotification();

  void validate();

  /////////////////////////////////////////////
  /// SmContextStatusNotification members

  /// <summary>
  ///
  /// </summary>
  StatusInfo getStatusInfo() const;
  void setStatusInfo(StatusInfo const& value);

  friend void to_json(nlohmann::json& j, const SmContextStatusNotification& o);
  friend void from_json(
      const nlohmann::json& j, SmContextStatusNotification& o);

 protected:
  StatusInfo m_StatusInfo;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* SmContextStatusNotification_H_ */
