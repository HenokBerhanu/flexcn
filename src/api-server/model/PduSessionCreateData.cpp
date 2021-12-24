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

#include "PduSessionCreateData.h"

namespace oai {
namespace flexcn_server {
namespace model {

PduSessionCreateData::PduSessionCreateData() {
  m_Supi                         = "";
  m_SupiIsSet                    = false;
  m_UnauthenticatedSupi          = false;
  m_UnauthenticatedSupiIsSet     = false;
  m_Pei                          = "";
  m_PeiIsSet                     = false;
  m_PduSessionId                 = 0;
  m_PduSessionIdIsSet            = false;
  m_Dnn                          = "";
  m_SNssaiIsSet                  = false;
  m_VsmfId                       = "";
  m_RequestTypeIsSet             = false;
  m_EpsBearerIdIsSet             = false;
  m_PgwS8cFteidIsSet             = false;
  m_VsmfPduSessionUri            = "";
  m_VcnTunnelInfoIsSet           = false;
  m_SecondAnTypeIsSet            = false;
  m_RatTypeIsSet                 = false;
  m_UeLocationIsSet              = false;
  m_UeTimeZone                   = "";
  m_UeTimeZoneIsSet              = false;
  m_AddUeLocationIsSet           = false;
  m_Gpsi                         = "";
  m_GpsiIsSet                    = false;
  m_N1SmInfoFromUeIsSet          = false;
  m_UnknownN1SmInfoIsSet         = false;
  m_SupportedFeatures            = "";
  m_SupportedFeaturesIsSet       = false;
  m_HPcfId                       = "";
  m_HPcfIdIsSet                  = false;
  m_HoPreparationIndication      = false;
  m_HoPreparationIndicationIsSet = false;
  m_SelModeIsSet                 = false;
  m_AlwaysOnRequested            = false;
  m_AlwaysOnRequestedIsSet       = false;
  m_UdmGroupId                   = "";
  m_UdmGroupIdIsSet              = false;
  m_RoutingIndicator             = "";
  m_RoutingIndicatorIsSet        = false;
  m_EpsInterworkingIndIsSet      = false;
  m_VSmfServiceInstanceId        = "";
  m_VSmfServiceInstanceIdIsSet   = false;
  m_RecoveryTime                 = "";
  m_RecoveryTimeIsSet            = false;
  m_RoamingChargingProfileIsSet  = false;
  m_ChargingId                   = "";
  m_ChargingIdIsSet              = false;
  m_OldPduSessionId              = 0;
  m_OldPduSessionIdIsSet         = false;
  m_EpsBearerCtxStatus           = "";
  m_EpsBearerCtxStatusIsSet      = false;
  m_AmfNfId                      = "";
  m_AmfNfIdIsSet                 = false;
  m_GuamiIsSet                   = false;
  m_CpCiotEnabled                = false;
  m_CpCiotEnabledIsSet           = false;
  m_InvokeNef                    = false;
  m_InvokeNefIsSet               = false;
  m_MaPduIndication              = false;
  m_MaPduIndicationIsSet         = false;
}

PduSessionCreateData::~PduSessionCreateData() {}

void PduSessionCreateData::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const PduSessionCreateData& o) {
  j = nlohmann::json();
  if (o.supiIsSet()) j["supi"] = o.m_Supi;
  if (o.unauthenticatedSupiIsSet())
    j["unauthenticatedSupi"] = o.m_UnauthenticatedSupi;
  if (o.peiIsSet()) j["pei"] = o.m_Pei;
  if (o.pduSessionIdIsSet()) j["pduSessionId"] = o.m_PduSessionId;
  j["dnn"] = o.m_Dnn;
  if (o.sNssaiIsSet()) j["sNssai"] = o.m_SNssai;
  j["vsmfId"]         = o.m_VsmfId;
  j["servingNetwork"] = o.m_ServingNetwork;
  if (o.requestTypeIsSet()) j["requestType"] = o.m_RequestType;
  if (o.epsBearerIdIsSet()) j["epsBearerId"] = o.m_EpsBearerId;
  if (o.pgwS8cFteidIsSet()) j["pgwS8cFteid"] = o.m_PgwS8cFteid;
  j["vsmfPduSessionUri"] = o.m_VsmfPduSessionUri;
  if (o.vcnTunnelInfoIsSet()) j["vcnTunnelInfo"] = o.m_VcnTunnelInfo;
  j["anType"] = o.m_AnType;
  if (o.secondAnTypeIsSet()) j["secondAnType"] = o.m_SecondAnType;
  if (o.ratTypeIsSet()) j["ratType"] = o.m_RatType;
  if (o.ueLocationIsSet()) j["ueLocation"] = o.m_UeLocation;
  if (o.ueTimeZoneIsSet()) j["ueTimeZone"] = o.m_UeTimeZone;
  if (o.addUeLocationIsSet()) j["addUeLocation"] = o.m_AddUeLocation;
  if (o.gpsiIsSet()) j["gpsi"] = o.m_Gpsi;
  if (o.n1SmInfoFromUeIsSet()) j["n1SmInfoFromUe"] = o.m_N1SmInfoFromUe;
  if (o.unknownN1SmInfoIsSet()) j["unknownN1SmInfo"] = o.m_UnknownN1SmInfo;
  if (o.supportedFeaturesIsSet())
    j["supportedFeatures"] = o.m_SupportedFeatures;
  if (o.hPcfIdIsSet()) j["hPcfId"] = o.m_HPcfId;
  if (o.hoPreparationIndicationIsSet())
    j["hoPreparationIndication"] = o.m_HoPreparationIndication;
  if (o.selModeIsSet()) j["selMode"] = o.m_SelMode;
  if (o.alwaysOnRequestedIsSet())
    j["alwaysOnRequested"] = o.m_AlwaysOnRequested;
  if (o.udmGroupIdIsSet()) j["udmGroupId"] = o.m_UdmGroupId;
  if (o.routingIndicatorIsSet()) j["routingIndicator"] = o.m_RoutingIndicator;
  if (o.epsInterworkingIndIsSet())
    j["epsInterworkingInd"] = o.m_EpsInterworkingInd;
  if (o.vSmfServiceInstanceIdIsSet())
    j["vSmfServiceInstanceId"] = o.m_VSmfServiceInstanceId;
  if (o.recoveryTimeIsSet()) j["recoveryTime"] = o.m_RecoveryTime;
  if (o.roamingChargingProfileIsSet())
    j["roamingChargingProfile"] = o.m_RoamingChargingProfile;
  if (o.chargingIdIsSet()) j["chargingId"] = o.m_ChargingId;
  if (o.oldPduSessionIdIsSet()) j["oldPduSessionId"] = o.m_OldPduSessionId;
  if (o.epsBearerCtxStatusIsSet())
    j["epsBearerCtxStatus"] = o.m_EpsBearerCtxStatus;
  if (o.amfNfIdIsSet()) j["amfNfId"] = o.m_AmfNfId;
  if (o.guamiIsSet()) j["guami"] = o.m_Guami;
  if (o.cpCiotEnabledIsSet()) j["cpCiotEnabled"] = o.m_CpCiotEnabled;
  if (o.invokeNefIsSet()) j["invokeNef"] = o.m_InvokeNef;
  if (o.maPduIndicationIsSet()) j["maPduIndication"] = o.m_MaPduIndication;
}

void from_json(const nlohmann::json& j, PduSessionCreateData& o) {
  if (j.find("supi") != j.end()) {
    j.at("supi").get_to(o.m_Supi);
    o.m_SupiIsSet = true;
  }
  if (j.find("unauthenticatedSupi") != j.end()) {
    j.at("unauthenticatedSupi").get_to(o.m_UnauthenticatedSupi);
    o.m_UnauthenticatedSupiIsSet = true;
  }
  if (j.find("pei") != j.end()) {
    j.at("pei").get_to(o.m_Pei);
    o.m_PeiIsSet = true;
  }
  if (j.find("pduSessionId") != j.end()) {
    j.at("pduSessionId").get_to(o.m_PduSessionId);
    o.m_PduSessionIdIsSet = true;
  }
  j.at("dnn").get_to(o.m_Dnn);
  if (j.find("sNssai") != j.end()) {
    j.at("sNssai").get_to(o.m_SNssai);
    o.m_SNssaiIsSet = true;
  }
  j.at("vsmfId").get_to(o.m_VsmfId);
  j.at("servingNetwork").get_to(o.m_ServingNetwork);
  if (j.find("requestType") != j.end()) {
    j.at("requestType").get_to(o.m_RequestType);
    o.m_RequestTypeIsSet = true;
  }
  if (j.find("epsBearerId") != j.end()) {
    j.at("epsBearerId").get_to(o.m_EpsBearerId);
    o.m_EpsBearerIdIsSet = true;
  }
  if (j.find("pgwS8cFteid") != j.end()) {
    j.at("pgwS8cFteid").get_to(o.m_PgwS8cFteid);
    o.m_PgwS8cFteidIsSet = true;
  }
  j.at("vsmfPduSessionUri").get_to(o.m_VsmfPduSessionUri);
  if (j.find("vcnTunnelInfo") != j.end()) {
    j.at("vcnTunnelInfo").get_to(o.m_VcnTunnelInfo);
    o.m_VcnTunnelInfoIsSet = true;
  }
  j.at("anType").get_to(o.m_AnType);
  if (j.find("secondAnType") != j.end()) {
    j.at("secondAnType").get_to(o.m_SecondAnType);
    o.m_SecondAnTypeIsSet = true;
  }
  if (j.find("ratType") != j.end()) {
    j.at("ratType").get_to(o.m_RatType);
    o.m_RatTypeIsSet = true;
  }
  if (j.find("ueLocation") != j.end()) {
    j.at("ueLocation").get_to(o.m_UeLocation);
    o.m_UeLocationIsSet = true;
  }
  if (j.find("ueTimeZone") != j.end()) {
    j.at("ueTimeZone").get_to(o.m_UeTimeZone);
    o.m_UeTimeZoneIsSet = true;
  }
  if (j.find("addUeLocation") != j.end()) {
    j.at("addUeLocation").get_to(o.m_AddUeLocation);
    o.m_AddUeLocationIsSet = true;
  }
  if (j.find("gpsi") != j.end()) {
    j.at("gpsi").get_to(o.m_Gpsi);
    o.m_GpsiIsSet = true;
  }
  if (j.find("n1SmInfoFromUe") != j.end()) {
    j.at("n1SmInfoFromUe").get_to(o.m_N1SmInfoFromUe);
    o.m_N1SmInfoFromUeIsSet = true;
  }
  if (j.find("unknownN1SmInfo") != j.end()) {
    j.at("unknownN1SmInfo").get_to(o.m_UnknownN1SmInfo);
    o.m_UnknownN1SmInfoIsSet = true;
  }
  if (j.find("supportedFeatures") != j.end()) {
    j.at("supportedFeatures").get_to(o.m_SupportedFeatures);
    o.m_SupportedFeaturesIsSet = true;
  }
  if (j.find("hPcfId") != j.end()) {
    j.at("hPcfId").get_to(o.m_HPcfId);
    o.m_HPcfIdIsSet = true;
  }
  if (j.find("hoPreparationIndication") != j.end()) {
    j.at("hoPreparationIndication").get_to(o.m_HoPreparationIndication);
    o.m_HoPreparationIndicationIsSet = true;
  }
  if (j.find("selMode") != j.end()) {
    j.at("selMode").get_to(o.m_SelMode);
    o.m_SelModeIsSet = true;
  }
  if (j.find("alwaysOnRequested") != j.end()) {
    j.at("alwaysOnRequested").get_to(o.m_AlwaysOnRequested);
    o.m_AlwaysOnRequestedIsSet = true;
  }
  if (j.find("udmGroupId") != j.end()) {
    j.at("udmGroupId").get_to(o.m_UdmGroupId);
    o.m_UdmGroupIdIsSet = true;
  }
  if (j.find("routingIndicator") != j.end()) {
    j.at("routingIndicator").get_to(o.m_RoutingIndicator);
    o.m_RoutingIndicatorIsSet = true;
  }
  if (j.find("epsInterworkingInd") != j.end()) {
    j.at("epsInterworkingInd").get_to(o.m_EpsInterworkingInd);
    o.m_EpsInterworkingIndIsSet = true;
  }
  if (j.find("vSmfServiceInstanceId") != j.end()) {
    j.at("vSmfServiceInstanceId").get_to(o.m_VSmfServiceInstanceId);
    o.m_VSmfServiceInstanceIdIsSet = true;
  }
  if (j.find("recoveryTime") != j.end()) {
    j.at("recoveryTime").get_to(o.m_RecoveryTime);
    o.m_RecoveryTimeIsSet = true;
  }
  if (j.find("roamingChargingProfile") != j.end()) {
    j.at("roamingChargingProfile").get_to(o.m_RoamingChargingProfile);
    o.m_RoamingChargingProfileIsSet = true;
  }
  if (j.find("chargingId") != j.end()) {
    j.at("chargingId").get_to(o.m_ChargingId);
    o.m_ChargingIdIsSet = true;
  }
  if (j.find("oldPduSessionId") != j.end()) {
    j.at("oldPduSessionId").get_to(o.m_OldPduSessionId);
    o.m_OldPduSessionIdIsSet = true;
  }
  if (j.find("epsBearerCtxStatus") != j.end()) {
    j.at("epsBearerCtxStatus").get_to(o.m_EpsBearerCtxStatus);
    o.m_EpsBearerCtxStatusIsSet = true;
  }
  if (j.find("amfNfId") != j.end()) {
    j.at("amfNfId").get_to(o.m_AmfNfId);
    o.m_AmfNfIdIsSet = true;
  }
  if (j.find("guami") != j.end()) {
    j.at("guami").get_to(o.m_Guami);
    o.m_GuamiIsSet = true;
  }
  if (j.find("cpCiotEnabled") != j.end()) {
    j.at("cpCiotEnabled").get_to(o.m_CpCiotEnabled);
    o.m_CpCiotEnabledIsSet = true;
  }
  if (j.find("invokeNef") != j.end()) {
    j.at("invokeNef").get_to(o.m_InvokeNef);
    o.m_InvokeNefIsSet = true;
  }
  if (j.find("maPduIndication") != j.end()) {
    j.at("maPduIndication").get_to(o.m_MaPduIndication);
    o.m_MaPduIndicationIsSet = true;
  }
}

std::string PduSessionCreateData::getSupi() const {
  return m_Supi;
}
void PduSessionCreateData::setSupi(std::string const& value) {
  m_Supi      = value;
  m_SupiIsSet = true;
}
bool PduSessionCreateData::supiIsSet() const {
  return m_SupiIsSet;
}
void PduSessionCreateData::unsetSupi() {
  m_SupiIsSet = false;
}
bool PduSessionCreateData::isUnauthenticatedSupi() const {
  return m_UnauthenticatedSupi;
}
void PduSessionCreateData::setUnauthenticatedSupi(bool const value) {
  m_UnauthenticatedSupi      = value;
  m_UnauthenticatedSupiIsSet = true;
}
bool PduSessionCreateData::unauthenticatedSupiIsSet() const {
  return m_UnauthenticatedSupiIsSet;
}
void PduSessionCreateData::unsetUnauthenticatedSupi() {
  m_UnauthenticatedSupiIsSet = false;
}
std::string PduSessionCreateData::getPei() const {
  return m_Pei;
}
void PduSessionCreateData::setPei(std::string const& value) {
  m_Pei      = value;
  m_PeiIsSet = true;
}
bool PduSessionCreateData::peiIsSet() const {
  return m_PeiIsSet;
}
void PduSessionCreateData::unsetPei() {
  m_PeiIsSet = false;
}
int32_t PduSessionCreateData::getPduSessionId() const {
  return m_PduSessionId;
}
void PduSessionCreateData::setPduSessionId(int32_t const value) {
  m_PduSessionId      = value;
  m_PduSessionIdIsSet = true;
}
bool PduSessionCreateData::pduSessionIdIsSet() const {
  return m_PduSessionIdIsSet;
}
void PduSessionCreateData::unsetPduSessionId() {
  m_PduSessionIdIsSet = false;
}
std::string PduSessionCreateData::getDnn() const {
  return m_Dnn;
}
void PduSessionCreateData::setDnn(std::string const& value) {
  m_Dnn = value;
}
Snssai PduSessionCreateData::getSNssai() const {
  return m_SNssai;
}
void PduSessionCreateData::setSNssai(Snssai const& value) {
  m_SNssai      = value;
  m_SNssaiIsSet = true;
}
bool PduSessionCreateData::sNssaiIsSet() const {
  return m_SNssaiIsSet;
}
void PduSessionCreateData::unsetSNssai() {
  m_SNssaiIsSet = false;
}
std::string PduSessionCreateData::getVsmfId() const {
  return m_VsmfId;
}
void PduSessionCreateData::setVsmfId(std::string const& value) {
  m_VsmfId = value;
}
PlmnId PduSessionCreateData::getServingNetwork() const {
  return m_ServingNetwork;
}
void PduSessionCreateData::setServingNetwork(PlmnId const& value) {
  m_ServingNetwork = value;
}
RequestType PduSessionCreateData::getRequestType() const {
  return m_RequestType;
}
void PduSessionCreateData::setRequestType(RequestType const& value) {
  m_RequestType      = value;
  m_RequestTypeIsSet = true;
}
bool PduSessionCreateData::requestTypeIsSet() const {
  return m_RequestTypeIsSet;
}
void PduSessionCreateData::unsetRequestType() {
  m_RequestTypeIsSet = false;
}
std::vector<int32_t>& PduSessionCreateData::getEpsBearerId() {
  return m_EpsBearerId;
}
bool PduSessionCreateData::epsBearerIdIsSet() const {
  return m_EpsBearerIdIsSet;
}
void PduSessionCreateData::unsetEpsBearerId() {
  m_EpsBearerIdIsSet = false;
}
std::string PduSessionCreateData::getPgwS8cFteid() const {
  return m_PgwS8cFteid;
}
void PduSessionCreateData::setPgwS8cFteid(std::string const& value) {
  m_PgwS8cFteid      = value;
  m_PgwS8cFteidIsSet = true;
}
bool PduSessionCreateData::pgwS8cFteidIsSet() const {
  return m_PgwS8cFteidIsSet;
}
void PduSessionCreateData::unsetPgwS8cFteid() {
  m_PgwS8cFteidIsSet = false;
}
std::string PduSessionCreateData::getVsmfPduSessionUri() const {
  return m_VsmfPduSessionUri;
}
void PduSessionCreateData::setVsmfPduSessionUri(std::string const& value) {
  m_VsmfPduSessionUri = value;
}
TunnelInfo PduSessionCreateData::getVcnTunnelInfo() const {
  return m_VcnTunnelInfo;
}
void PduSessionCreateData::setVcnTunnelInfo(TunnelInfo const& value) {
  m_VcnTunnelInfo      = value;
  m_VcnTunnelInfoIsSet = true;
}
bool PduSessionCreateData::vcnTunnelInfoIsSet() const {
  return m_VcnTunnelInfoIsSet;
}
void PduSessionCreateData::unsetVcnTunnelInfo() {
  m_VcnTunnelInfoIsSet = false;
}
AccessType PduSessionCreateData::getAnType() const {
  return m_AnType;
}
void PduSessionCreateData::setAnType(AccessType const& value) {
  m_AnType = value;
}
AccessType PduSessionCreateData::getSecondAnType() const {
  return m_SecondAnType;
}
void PduSessionCreateData::setSecondAnType(AccessType const& value) {
  m_SecondAnType      = value;
  m_SecondAnTypeIsSet = true;
}
bool PduSessionCreateData::secondAnTypeIsSet() const {
  return m_SecondAnTypeIsSet;
}
void PduSessionCreateData::unsetSecondAnType() {
  m_SecondAnTypeIsSet = false;
}
RatType PduSessionCreateData::getRatType() const {
  return m_RatType;
}
void PduSessionCreateData::setRatType(RatType const& value) {
  m_RatType      = value;
  m_RatTypeIsSet = true;
}
bool PduSessionCreateData::ratTypeIsSet() const {
  return m_RatTypeIsSet;
}
void PduSessionCreateData::unsetRatType() {
  m_RatTypeIsSet = false;
}
UserLocation PduSessionCreateData::getUeLocation() const {
  return m_UeLocation;
}
void PduSessionCreateData::setUeLocation(UserLocation const& value) {
  m_UeLocation      = value;
  m_UeLocationIsSet = true;
}
bool PduSessionCreateData::ueLocationIsSet() const {
  return m_UeLocationIsSet;
}
void PduSessionCreateData::unsetUeLocation() {
  m_UeLocationIsSet = false;
}
std::string PduSessionCreateData::getUeTimeZone() const {
  return m_UeTimeZone;
}
void PduSessionCreateData::setUeTimeZone(std::string const& value) {
  m_UeTimeZone      = value;
  m_UeTimeZoneIsSet = true;
}
bool PduSessionCreateData::ueTimeZoneIsSet() const {
  return m_UeTimeZoneIsSet;
}
void PduSessionCreateData::unsetUeTimeZone() {
  m_UeTimeZoneIsSet = false;
}
UserLocation PduSessionCreateData::getAddUeLocation() const {
  return m_AddUeLocation;
}
void PduSessionCreateData::setAddUeLocation(UserLocation const& value) {
  m_AddUeLocation      = value;
  m_AddUeLocationIsSet = true;
}
bool PduSessionCreateData::addUeLocationIsSet() const {
  return m_AddUeLocationIsSet;
}
void PduSessionCreateData::unsetAddUeLocation() {
  m_AddUeLocationIsSet = false;
}
std::string PduSessionCreateData::getGpsi() const {
  return m_Gpsi;
}
void PduSessionCreateData::setGpsi(std::string const& value) {
  m_Gpsi      = value;
  m_GpsiIsSet = true;
}
bool PduSessionCreateData::gpsiIsSet() const {
  return m_GpsiIsSet;
}
void PduSessionCreateData::unsetGpsi() {
  m_GpsiIsSet = false;
}
RefToBinaryData PduSessionCreateData::getN1SmInfoFromUe() const {
  return m_N1SmInfoFromUe;
}
void PduSessionCreateData::setN1SmInfoFromUe(RefToBinaryData const& value) {
  m_N1SmInfoFromUe      = value;
  m_N1SmInfoFromUeIsSet = true;
}
bool PduSessionCreateData::n1SmInfoFromUeIsSet() const {
  return m_N1SmInfoFromUeIsSet;
}
void PduSessionCreateData::unsetN1SmInfoFromUe() {
  m_N1SmInfoFromUeIsSet = false;
}
RefToBinaryData PduSessionCreateData::getUnknownN1SmInfo() const {
  return m_UnknownN1SmInfo;
}
void PduSessionCreateData::setUnknownN1SmInfo(RefToBinaryData const& value) {
  m_UnknownN1SmInfo      = value;
  m_UnknownN1SmInfoIsSet = true;
}
bool PduSessionCreateData::unknownN1SmInfoIsSet() const {
  return m_UnknownN1SmInfoIsSet;
}
void PduSessionCreateData::unsetUnknownN1SmInfo() {
  m_UnknownN1SmInfoIsSet = false;
}
std::string PduSessionCreateData::getSupportedFeatures() const {
  return m_SupportedFeatures;
}
void PduSessionCreateData::setSupportedFeatures(std::string const& value) {
  m_SupportedFeatures      = value;
  m_SupportedFeaturesIsSet = true;
}
bool PduSessionCreateData::supportedFeaturesIsSet() const {
  return m_SupportedFeaturesIsSet;
}
void PduSessionCreateData::unsetSupportedFeatures() {
  m_SupportedFeaturesIsSet = false;
}
std::string PduSessionCreateData::getHPcfId() const {
  return m_HPcfId;
}
void PduSessionCreateData::setHPcfId(std::string const& value) {
  m_HPcfId      = value;
  m_HPcfIdIsSet = true;
}
bool PduSessionCreateData::hPcfIdIsSet() const {
  return m_HPcfIdIsSet;
}
void PduSessionCreateData::unsetHPcfId() {
  m_HPcfIdIsSet = false;
}
bool PduSessionCreateData::isHoPreparationIndication() const {
  return m_HoPreparationIndication;
}
void PduSessionCreateData::setHoPreparationIndication(bool const value) {
  m_HoPreparationIndication      = value;
  m_HoPreparationIndicationIsSet = true;
}
bool PduSessionCreateData::hoPreparationIndicationIsSet() const {
  return m_HoPreparationIndicationIsSet;
}
void PduSessionCreateData::unsetHoPreparationIndication() {
  m_HoPreparationIndicationIsSet = false;
}
DnnSelectionMode PduSessionCreateData::getSelMode() const {
  return m_SelMode;
}
void PduSessionCreateData::setSelMode(DnnSelectionMode const& value) {
  m_SelMode      = value;
  m_SelModeIsSet = true;
}
bool PduSessionCreateData::selModeIsSet() const {
  return m_SelModeIsSet;
}
void PduSessionCreateData::unsetSelMode() {
  m_SelModeIsSet = false;
}
bool PduSessionCreateData::isAlwaysOnRequested() const {
  return m_AlwaysOnRequested;
}
void PduSessionCreateData::setAlwaysOnRequested(bool const value) {
  m_AlwaysOnRequested      = value;
  m_AlwaysOnRequestedIsSet = true;
}
bool PduSessionCreateData::alwaysOnRequestedIsSet() const {
  return m_AlwaysOnRequestedIsSet;
}
void PduSessionCreateData::unsetAlwaysOnRequested() {
  m_AlwaysOnRequestedIsSet = false;
}
std::string PduSessionCreateData::getUdmGroupId() const {
  return m_UdmGroupId;
}
void PduSessionCreateData::setUdmGroupId(std::string const& value) {
  m_UdmGroupId      = value;
  m_UdmGroupIdIsSet = true;
}
bool PduSessionCreateData::udmGroupIdIsSet() const {
  return m_UdmGroupIdIsSet;
}
void PduSessionCreateData::unsetUdmGroupId() {
  m_UdmGroupIdIsSet = false;
}
std::string PduSessionCreateData::getRoutingIndicator() const {
  return m_RoutingIndicator;
}
void PduSessionCreateData::setRoutingIndicator(std::string const& value) {
  m_RoutingIndicator      = value;
  m_RoutingIndicatorIsSet = true;
}
bool PduSessionCreateData::routingIndicatorIsSet() const {
  return m_RoutingIndicatorIsSet;
}
void PduSessionCreateData::unsetRoutingIndicator() {
  m_RoutingIndicatorIsSet = false;
}
EpsInterworkingIndication PduSessionCreateData::getEpsInterworkingInd() const {
  return m_EpsInterworkingInd;
}
void PduSessionCreateData::setEpsInterworkingInd(
    EpsInterworkingIndication const& value) {
  m_EpsInterworkingInd      = value;
  m_EpsInterworkingIndIsSet = true;
}
bool PduSessionCreateData::epsInterworkingIndIsSet() const {
  return m_EpsInterworkingIndIsSet;
}
void PduSessionCreateData::unsetEpsInterworkingInd() {
  m_EpsInterworkingIndIsSet = false;
}
std::string PduSessionCreateData::getVSmfServiceInstanceId() const {
  return m_VSmfServiceInstanceId;
}
void PduSessionCreateData::setVSmfServiceInstanceId(std::string const& value) {
  m_VSmfServiceInstanceId      = value;
  m_VSmfServiceInstanceIdIsSet = true;
}
bool PduSessionCreateData::vSmfServiceInstanceIdIsSet() const {
  return m_VSmfServiceInstanceIdIsSet;
}
void PduSessionCreateData::unsetVSmfServiceInstanceId() {
  m_VSmfServiceInstanceIdIsSet = false;
}
std::string PduSessionCreateData::getRecoveryTime() const {
  return m_RecoveryTime;
}
void PduSessionCreateData::setRecoveryTime(std::string const& value) {
  m_RecoveryTime      = value;
  m_RecoveryTimeIsSet = true;
}
bool PduSessionCreateData::recoveryTimeIsSet() const {
  return m_RecoveryTimeIsSet;
}
void PduSessionCreateData::unsetRecoveryTime() {
  m_RecoveryTimeIsSet = false;
}
RoamingChargingProfile PduSessionCreateData::getRoamingChargingProfile() const {
  return m_RoamingChargingProfile;
}
void PduSessionCreateData::setRoamingChargingProfile(
    RoamingChargingProfile const& value) {
  m_RoamingChargingProfile      = value;
  m_RoamingChargingProfileIsSet = true;
}
bool PduSessionCreateData::roamingChargingProfileIsSet() const {
  return m_RoamingChargingProfileIsSet;
}
void PduSessionCreateData::unsetRoamingChargingProfile() {
  m_RoamingChargingProfileIsSet = false;
}
std::string PduSessionCreateData::getChargingId() const {
  return m_ChargingId;
}
void PduSessionCreateData::setChargingId(std::string const& value) {
  m_ChargingId      = value;
  m_ChargingIdIsSet = true;
}
bool PduSessionCreateData::chargingIdIsSet() const {
  return m_ChargingIdIsSet;
}
void PduSessionCreateData::unsetChargingId() {
  m_ChargingIdIsSet = false;
}
int32_t PduSessionCreateData::getOldPduSessionId() const {
  return m_OldPduSessionId;
}
void PduSessionCreateData::setOldPduSessionId(int32_t const value) {
  m_OldPduSessionId      = value;
  m_OldPduSessionIdIsSet = true;
}
bool PduSessionCreateData::oldPduSessionIdIsSet() const {
  return m_OldPduSessionIdIsSet;
}
void PduSessionCreateData::unsetOldPduSessionId() {
  m_OldPduSessionIdIsSet = false;
}
std::string PduSessionCreateData::getEpsBearerCtxStatus() const {
  return m_EpsBearerCtxStatus;
}
void PduSessionCreateData::setEpsBearerCtxStatus(std::string const& value) {
  m_EpsBearerCtxStatus      = value;
  m_EpsBearerCtxStatusIsSet = true;
}
bool PduSessionCreateData::epsBearerCtxStatusIsSet() const {
  return m_EpsBearerCtxStatusIsSet;
}
void PduSessionCreateData::unsetEpsBearerCtxStatus() {
  m_EpsBearerCtxStatusIsSet = false;
}
std::string PduSessionCreateData::getAmfNfId() const {
  return m_AmfNfId;
}
void PduSessionCreateData::setAmfNfId(std::string const& value) {
  m_AmfNfId      = value;
  m_AmfNfIdIsSet = true;
}
bool PduSessionCreateData::amfNfIdIsSet() const {
  return m_AmfNfIdIsSet;
}
void PduSessionCreateData::unsetAmfNfId() {
  m_AmfNfIdIsSet = false;
}
Guami PduSessionCreateData::getGuami() const {
  return m_Guami;
}
void PduSessionCreateData::setGuami(Guami const& value) {
  m_Guami      = value;
  m_GuamiIsSet = true;
}
bool PduSessionCreateData::guamiIsSet() const {
  return m_GuamiIsSet;
}
void PduSessionCreateData::unsetGuami() {
  m_GuamiIsSet = false;
}
bool PduSessionCreateData::isCpCiotEnabled() const {
  return m_CpCiotEnabled;
}
void PduSessionCreateData::setCpCiotEnabled(bool const value) {
  m_CpCiotEnabled      = value;
  m_CpCiotEnabledIsSet = true;
}
bool PduSessionCreateData::cpCiotEnabledIsSet() const {
  return m_CpCiotEnabledIsSet;
}
void PduSessionCreateData::unsetCpCiotEnabled() {
  m_CpCiotEnabledIsSet = false;
}
bool PduSessionCreateData::isInvokeNef() const {
  return m_InvokeNef;
}
void PduSessionCreateData::setInvokeNef(bool const value) {
  m_InvokeNef      = value;
  m_InvokeNefIsSet = true;
}
bool PduSessionCreateData::invokeNefIsSet() const {
  return m_InvokeNefIsSet;
}
void PduSessionCreateData::unsetInvokeNef() {
  m_InvokeNefIsSet = false;
}
bool PduSessionCreateData::isMaPduIndication() const {
  return m_MaPduIndication;
}
void PduSessionCreateData::setMaPduIndication(bool const value) {
  m_MaPduIndication      = value;
  m_MaPduIndicationIsSet = true;
}
bool PduSessionCreateData::maPduIndicationIsSet() const {
  return m_MaPduIndicationIsSet;
}
void PduSessionCreateData::unsetMaPduIndication() {
  m_MaPduIndicationIsSet = false;
}

}  // namespace model
}  // namespace flexcn_server
}  // namespace oai
