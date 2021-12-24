/**
* FlexCN_4G_API
* This API allows SPGWC to communicate with FlexCN. Equivalent of LLMEC API.  
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

#ifndef DEFAULT_API_IMPL_H_
#define DEFAULT_API_IMPL_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <NorthBound4GApi.h>

#include <pistache/optional.h>

#include "Bearer.h"
#include <service4g/app4G.hpp>

#include <string>

namespace oai {
namespace flexcn_server {
namespace api {

using namespace oai::flexcn_server::model;

class NorthBound4GApiImpl : public oai::flexcn_server::api::NorthBound4GApi {

private: 
    std::shared_ptr<App4G> m_flexcn_app;

public:
    explicit NorthBound4GApiImpl(const std::shared_ptr<Pistache::Rest::Router>& rtr, std::shared_ptr<App4G> flexcn_app_inst);
    ~NorthBound4GApiImpl() override = default;

    void add_bearer(const Bearer &bearer, Pistache::Http::ResponseWriter &response);
    void delete_a_single_bearer_by_imsi_bearer(const std::string &imsiBearer, Pistache::Http::ResponseWriter &response);
    void delete_a_single_bearer_by_id(const std::string &id, Pistache::Http::ResponseWriter &response);
    void delete_all_bearers(Pistache::Http::ResponseWriter &response);
    void get_stats(Pistache::Http::ResponseWriter &response);
    void get_stats_by_imsi_bearer(const std::string &imsiBearer, Pistache::Http::ResponseWriter &response);
    void get_stats_by_id(const std::string &id, Pistache::Http::ResponseWriter &response);

};

}  // namespace api
}  // namespace flexcn_server
}  // namespace oai



#endif