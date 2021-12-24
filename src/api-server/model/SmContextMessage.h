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
 * Inline_object.h
 *
 *
 */

#ifndef Sm_Context_Message_H_
#define Sm_Context_Message_H_

#include "SmContextCreateData.h"
#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class SmContextMessage {
 public:
  SmContextMessage();
  virtual ~SmContextMessage();

  void validate();

  /////////////////////////////////////////////
  /// Inline_object members

  /// <summary>
  ///
  /// </summary>
  SmContextCreateData getJsonData() const;
  void setJsonData(SmContextCreateData const& value);
  bool jsonDataIsSet() const;
  void unsetJsonData();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN1SmMessage() const;
  void setBinaryDataN1SmMessage(std::string const& value);
  bool binaryDataN1SmMessageIsSet() const;
  void unsetBinaryDataN1SmMessage();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2SmInformation() const;
  void setBinaryDataN2SmInformation(std::string const& value);
  bool binaryDataN2SmInformationIsSet() const;
  void unsetBinaryDataN2SmInformation();

  friend void to_json(nlohmann::json& j, const SmContextMessage& o);
  friend void from_json(const nlohmann::json& j, SmContextMessage& o);

 protected:
  SmContextCreateData m_JsonData;
  bool m_JsonDataIsSet;
  std::string m_BinaryDataN1SmMessage;
  bool m_BinaryDataN1SmMessageIsSet;
  std::string m_BinaryDataN2SmInformation;
  bool m_BinaryDataN2SmInformationIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* Sm_Context_Message_H_ */
