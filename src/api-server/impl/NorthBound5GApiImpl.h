/**
* FlexCN Northbound API
* This API allows xApps to communicate with FlexCN. 
*
* The version of the OpenAPI document: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

/*
* DefaultApiImpl.h
*
* 
*/

#ifndef NB4G_API_IMPL_H_
#define NB4G_API_IMPL_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <NorthBound5GApi.h>

#include <pistache/optional.h>

#include "Event.h"
#include "StatPerUE.h"
#include "iApp.hpp"
#include "monitoringApp.hpp"

// #include "flexcn_app.hpp"
#ifdef WITH_5G_SMF
#include "smf5g/smf_app.hpp"
#endif

#ifdef WITH_5G_AMF
#include "amf5g/amf_app.hpp"
#endif

#include <string>

namespace oai::flexcn_server::api
{

using namespace oai::flexcn_server::model;

class NorthBound5GApiImpl : public oai::flexcn_server::api::NorthBound5GApi {
private: 

    // adding your iapps here
    #ifdef WITH_5G_SMF
    SMFApp* m_smf_app;
    #endif
    
    #ifdef WITH_5G_AMF
    AMFApp* m_amf_app;
    #endif
    std::map<int, std::shared_ptr<MonitoringAppAPI>> m_iapps;

public:
    explicit NorthBound5GApiImpl(const std::shared_ptr<Pistache::Rest::Router>& rtr);
    ~NorthBound5GApiImpl() override = default;

    void get_stats(Pistache::Http::ResponseWriter &response);
    void get_stats_per_ue(const std::string &ueid, Pistache::Http::ResponseWriter &response);
    void trigger_subcribe(const std::string &ueid, Pistache::Http::ResponseWriter &response);
    void add_monitoring_iapp(const std::shared_ptr<MonitoringAppAPI>& app);
    void add_control_iapp(const std::shared_ptr<iApp_api>& app);

};

} // namespace oai::flexcn_server::api



#endif
