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
 * ChangeItem.h
 *
 *
 */

#ifndef ChangeItem_H_
#define ChangeItem_H_

#include "ChangeType.h"
#include <string>
//#include "AnyType.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class ChangeItem {
 public:
  ChangeItem();
  virtual ~ChangeItem();

  void validate();

  /////////////////////////////////////////////
  /// ChangeItem members

  /// <summary>
  ///
  /// </summary>
  ChangeType getOp() const;
  void setOp(ChangeType const& value);
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
  std::string getOrigValue() const;
  void setOrigValue(std::string const& value);
  bool origValueIsSet() const;
  void unsetOrigValue();
  /// <summary>
  ///
  /// </summary>
  std::string getNewValue() const;
  void setNewValue(std::string const& value);
  bool newValueIsSet() const;
  void unsetNewValue();

  friend void to_json(nlohmann::json& j, const ChangeItem& o);
  friend void from_json(const nlohmann::json& j, ChangeItem& o);

 protected:
  ChangeType m_Op;

  std::string m_Path;

  std::string m_From;
  bool m_FromIsSet;
  std::string m_OrigValue;
  bool m_OrigValueIsSet;
  std::string m_NewValue;
  bool m_NewValueIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* ChangeItem_H_ */
