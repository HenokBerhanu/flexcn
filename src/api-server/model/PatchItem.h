/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
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
 * PatchItem.h
 *
 *
 */

#ifndef PatchItem_H_
#define PatchItem_H_

#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class PatchItem {
 public:
  PatchItem();
  virtual ~PatchItem();

  void validate();

  /////////////////////////////////////////////
  /// PatchItem members

  /// <summary>
  ///
  /// </summary>
  std::string getOp() const;
  void setOp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getPath() const;
  void setPath(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getFrom() const;
  void setFrom(std::string const& value);
  bool fromIsSet() const;
  void unsetFrom();
  /// <summary>
  ///
  /// </summary>
  std::string getValue() const;
  void setValue(std::string const& value);
  bool valueIsSet() const;
  void unsetValue();

  friend void to_json(nlohmann::json& j, const PatchItem& o);
  friend void from_json(const nlohmann::json& j, PatchItem& o);

 protected:
  std::string m_Op;

  std::string m_Path;

  std::string m_From;
  bool m_FromIsSet;
  std::string m_Value;
  bool m_ValueIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* PatchItem_H_ */
