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
 * Ecgi.h
 *
 *
 */

#ifndef Ecgi_H_
#define Ecgi_H_

#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
///
/// </summary>
class Ecgi {
 public:
  Ecgi();
  virtual ~Ecgi();

  void validate();

  /////////////////////////////////////////////
  /// Ecgi members

  /// <summary>
  ///
  /// </summary>
  PlmnId getPlmnId() const;
  void setPlmnId(PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getEutraCellId() const;
  void setEutraCellId(std::string const& value);

  friend void to_json(nlohmann::json& j, const Ecgi& o);
  friend void from_json(const nlohmann::json& j, Ecgi& o);

 protected:
  PlmnId m_PlmnId;

  std::string m_EutraCellId;
};

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai

#endif /* Ecgi_H_ */
