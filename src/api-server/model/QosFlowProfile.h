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
 * QosFlowProfile.h
 *
 *
 */

#ifndef QosFlowProfile_H_
#define QosFlowProfile_H_

#include "AdditionalQosFlowInfo.h"
#include "Dynamic5Qi.h"
#include "GbrQosFlowInformation.h"
#include "ReflectiveQoSAttribute.h"
#include "Arp.h"
#include "NonDynamic5Qi.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class QosFlowProfile {
 public:
  QosFlowProfile();
  virtual ~QosFlowProfile();

  void validate();

  /////////////////////////////////////////////
  /// QosFlowProfile members

  /// <summary>
  ///
  /// </summary>
  int32_t get5qi() const;
  void set5qi(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  NonDynamic5Qi getNonDynamic5Qi() const;
  void setNonDynamic5Qi(NonDynamic5Qi const& value);
  bool nonDynamic5QiIsSet() const;
  void unsetNonDynamic5Qi();
  /// <summary>
  ///
  /// </summary>
  Dynamic5Qi getDynamic5Qi() const;
  void setDynamic5Qi(Dynamic5Qi const& value);
  bool dynamic5QiIsSet() const;
  void unsetDynamic5Qi();
  /// <summary>
  ///
  /// </summary>
  Arp getArp() const;
  void setArp(Arp const& value);
  bool arpIsSet() const;
  void unsetArp();
  /// <summary>
  ///
  /// </summary>
  GbrQosFlowInformation getGbrQosFlowInfo() const;
  void setGbrQosFlowInfo(GbrQosFlowInformation const& value);
  bool gbrQosFlowInfoIsSet() const;
  void unsetGbrQosFlowInfo();
  /// <summary>
  ///
  /// </summary>
  ReflectiveQoSAttribute getRqa() const;
  void setRqa(ReflectiveQoSAttribute const& value);
  bool rqaIsSet() const;
  void unsetRqa();
  /// <summary>
  ///
  /// </summary>
  AdditionalQosFlowInfo getAdditionalQosFlowInfo() const;
  void setAdditionalQosFlowInfo(AdditionalQosFlowInfo const& value);
  bool additionalQosFlowInfoIsSet() const;
  void unsetAdditionalQosFlowInfo();

  friend void to_json(nlohmann::json& j, const QosFlowProfile& o);
  friend void from_json(const nlohmann::json& j, QosFlowProfile& o);

 protected:
  int32_t m__5qi;

  NonDynamic5Qi m_NonDynamic5Qi;
  bool m_NonDynamic5QiIsSet;
  Dynamic5Qi m_Dynamic5Qi;
  bool m_Dynamic5QiIsSet;
  Arp m_Arp;
  bool m_ArpIsSet;
  GbrQosFlowInformation m_GbrQosFlowInfo;
  bool m_GbrQosFlowInfoIsSet;
  ReflectiveQoSAttribute m_Rqa;
  bool m_RqaIsSet;
  AdditionalQosFlowInfo m_AdditionalQosFlowInfo;
  bool m_AdditionalQosFlowInfoIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* QosFlowProfile_H_ */
