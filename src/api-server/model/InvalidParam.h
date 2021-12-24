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
 * InvalidParam.h
 *
 *
 */

#ifndef InvalidParam_H_
#define InvalidParam_H_

#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class InvalidParam {
 public:
  InvalidParam();
  virtual ~InvalidParam();

  void validate();

  /////////////////////////////////////////////
  /// InvalidParam members

  /// <summary>
  ///
  /// </summary>
  std::string getParam() const;
  void setParam(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getReason() const;
  void setReason(std::string const& value);
  bool reasonIsSet() const;
  void unsetReason();

  friend void to_json(nlohmann::json& j, const InvalidParam& o);
  friend void from_json(const nlohmann::json& j, InvalidParam& o);

 protected:
  std::string m_Param;

  std::string m_Reason;
  bool m_ReasonIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* InvalidParam_H_ */
