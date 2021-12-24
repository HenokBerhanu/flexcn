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
 * QosFlowReleaseRequestItem.h
 *
 *
 */

#ifndef QosFlowReleaseRequestItem_H_
#define QosFlowReleaseRequestItem_H_

#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class QosFlowReleaseRequestItem {
 public:
  QosFlowReleaseRequestItem();
  virtual ~QosFlowReleaseRequestItem();

  void validate();

  /////////////////////////////////////////////
  /// QosFlowReleaseRequestItem members

  /// <summary>
  ///
  /// </summary>
  int32_t getQfi() const;
  void setQfi(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getQosRules() const;
  void setQosRules(std::string const& value);
  bool qosRulesIsSet() const;
  void unsetQosRules();
  /// <summary>
  ///
  /// </summary>
  std::string getQosFlowDescription() const;
  void setQosFlowDescription(std::string const& value);
  bool qosFlowDescriptionIsSet() const;
  void unsetQosFlowDescription();

  friend void to_json(nlohmann::json& j, const QosFlowReleaseRequestItem& o);
  friend void from_json(const nlohmann::json& j, QosFlowReleaseRequestItem& o);

 protected:
  int32_t m_Qfi;

  std::string m_QosRules;
  bool m_QosRulesIsSet;
  std::string m_QosFlowDescription;
  bool m_QosFlowDescriptionIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* QosFlowReleaseRequestItem_H_ */
