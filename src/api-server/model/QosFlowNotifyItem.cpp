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

#include "QosFlowNotifyItem.h"

namespace oai {
namespace flexcn_server {
namespace model {

QosFlowNotifyItem::QosFlowNotifyItem() {
  m_Qfi = 0;
}

QosFlowNotifyItem::~QosFlowNotifyItem() {}

void QosFlowNotifyItem::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const QosFlowNotifyItem& o) {
  j                      = nlohmann::json();
  j["qfi"]               = o.m_Qfi;
  j["notificationCause"] = o.m_NotificationCause;
}

void from_json(const nlohmann::json& j, QosFlowNotifyItem& o) {
  j.at("qfi").get_to(o.m_Qfi);
  j.at("notificationCause").get_to(o.m_NotificationCause);
}

int32_t QosFlowNotifyItem::getQfi() const {
  return m_Qfi;
}
void QosFlowNotifyItem::setQfi(int32_t const value) {
  m_Qfi = value;
}
NotificationCause QosFlowNotifyItem::getNotificationCause() const {
  return m_NotificationCause;
}
void QosFlowNotifyItem::setNotificationCause(NotificationCause const& value) {
  m_NotificationCause = value;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
