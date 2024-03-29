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
 * NotificationData.h
 *
 *
 */

#ifndef NotificationData_H_
#define NotificationData_H_

#include "NFProfile.h"
#include "ChangeItem.h"
#include <string>
#include "NotificationEventType.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class NotificationData {
 public:
  NotificationData();
  virtual ~NotificationData();

  void validate();

  /////////////////////////////////////////////
  /// NotificationData members

  /// <summary>
  ///
  /// </summary>
  std::string getEvent() const;
  void setEvent(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNfInstanceUri() const;
  void setNfInstanceUri(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  NFProfile getNfProfile() const;
  void setNfProfile(NFProfile const& value);
  bool nfProfileIsSet() const;
  void unsetNfProfile();
  /// <summary>
  ///
  /// </summary>
  std::vector<ChangeItem>& getProfileChanges();
  void setProfileChanges(std::vector<ChangeItem> const& value);
  bool profileChangesIsSet() const;
  void unsetProfileChanges();

  friend void to_json(nlohmann::json& j, const NotificationData& o);
  friend void from_json(const nlohmann::json& j, NotificationData& o);

 protected:
  std::string m_Event;

  std::string m_NfInstanceUri;

  NFProfile m_NfProfile;
  bool m_NfProfileIsSet;
  std::vector<ChangeItem> m_ProfileChanges;
  bool m_ProfileChangesIsSet;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* NotificationData_H_ */
