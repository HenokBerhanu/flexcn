/**
 * Nsmf_EventExposure
 * Session Management Event Exposure Service. © 2019, 3GPP Organizational
 * Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * RouteInformation.h
 *
 *
 */

#ifndef RouteInformation_H_
#define RouteInformation_H_

#include <string>
#include "Ipv6Addr.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
// typedef std::string Ipv6Addr;

class RouteInformation {
 public:
  RouteInformation();
  virtual ~RouteInformation();

  void validate();

  /////////////////////////////////////////////
  /// RouteInformation members

  /// <summary>
  ///
  /// </summary>
  std::string getIpv4Addr() const;
  void setIpv4Addr(std::string const& value);
  bool ipv4AddrIsSet() const;
  void unsetIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  Ipv6Addr getIpv6Addr() const;
  void setIpv6Addr(Ipv6Addr const& value);
  bool ipv6AddrIsSet() const;
  void unsetIpv6Addr();
  /// <summary>
  ///
  /// </summary>
  int32_t getPortNumber() const;
  void setPortNumber(int32_t const value);

  friend void to_json(nlohmann::json& j, const RouteInformation& o);
  friend void from_json(const nlohmann::json& j, RouteInformation& o);

 protected:
  std::string m_Ipv4Addr;
  bool m_Ipv4AddrIsSet;
  Ipv6Addr m_Ipv6Addr;
  bool m_Ipv6AddrIsSet;
  int32_t m_PortNumber;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* RouteInformation_H_ */
