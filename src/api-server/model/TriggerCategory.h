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
 * TriggerCategory.h
 *
 *
 */

#ifndef TriggerCategory_H_
#define TriggerCategory_H_

#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class TriggerCategory {
 public:
  TriggerCategory();
  virtual ~TriggerCategory();

  void validate();

  /////////////////////////////////////////////
  /// TriggerCategory members

  friend void to_json(nlohmann::json& j, const TriggerCategory& o);
  friend void from_json(const nlohmann::json& j, TriggerCategory& o);

 protected:
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* TriggerCategory_H_ */