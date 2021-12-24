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
 * Trigger.h
 *
 *
 */

#ifndef Trigger_H_
#define Trigger_H_

#include "TriggerCategory.h"
#include "TriggerType.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class Trigger {
 public:
  Trigger();
  virtual ~Trigger();

  void validate();

  /////////////////////////////////////////////
  /// Trigger members

  /// <summary>
  ///
  /// </summary>
  TriggerType getTriggerType() const;
  void setTriggerType(TriggerType const& value);
  /// <summary>
  ///
  /// </summary>
  TriggerCategory getTriggerCategory() const;
  void setTriggerCategory(TriggerCategory const& value);
  /// <summary>
  ///
  /// </summary>
  int32_t getTimeLimit() const;
  void setTimeLimit(int32_t const value);
  bool timeLimitIsSet() const;
  void unsetTimeLimit();
  /// <summary>
  ///
  /// </summary>
  int32_t getVolumeLimit() const;
  void setVolumeLimit(int32_t const value);
  bool volumeLimitIsSet() const;
  void unsetVolumeLimit();
  /// <summary>
  ///
  /// </summary>
  int64_t getVolumeLimit64() const;
  void setVolumeLimit64(int64_t const value);
  bool volumeLimit64IsSet() const;
  void unsetVolumeLimit64();
  /// <summary>
  ///
  /// </summary>
  int32_t getMaxNumberOfccc() const;
  void setMaxNumberOfccc(int32_t const value);
  bool maxNumberOfcccIsSet() const;
  void unsetMaxNumberOfccc();

  friend void to_json(nlohmann::json& j, const Trigger& o);
  friend void from_json(const nlohmann::json& j, Trigger& o);

 protected:
  TriggerType m_TriggerType;

  TriggerCategory m_TriggerCategory;

  int32_t m_TimeLimit;
  bool m_TimeLimitIsSet;
  int32_t m_VolumeLimit;
  bool m_VolumeLimitIsSet;
  int64_t m_VolumeLimit64;
  bool m_VolumeLimit64IsSet;
  int32_t m_MaxNumberOfccc;
  bool m_MaxNumberOfcccIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* Trigger_H_ */
