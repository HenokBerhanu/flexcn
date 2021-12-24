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
 * NorthBoundApi.h
 *
 * 
 */

#ifndef NorthBoundAPI_H_
#define NorthBoundAPI_H_


#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>

#include <utility>

#include "Event.h"
#include "StatPerUE.h"
#include <string>

namespace oai::flexcn_server::api
{

class  NorthBound5GApi {
public:
    explicit NorthBound5GApi(const std::shared_ptr<Pistache::Rest::Router>& rtr);
    virtual ~NorthBound5GApi() = default;
    void init();

    static const std::string base;

private:
    void setupRoutes();

    void get_stats_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void get_stats_per_ue_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void trigger_subcribe_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void default_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    const std::shared_ptr<Pistache::Rest::Router> router;

    /// <summary>
    /// Helper function to handle unexpected Exceptions during Parameter parsing and validation.
    /// May be overriden to return custom error formats.
    /// </summary>
    virtual std::pair<Pistache::Http::Code, std::string> handleParsingException(const std::exception& ex) const noexcept;

    /// <summary>
    /// Helper function to handle unexpected Exceptions during processing of the request in handler functions.
    /// May be overriden to return custom error formats.
    /// </summary>
    virtual std::pair<Pistache::Http::Code, std::string> handleOperationException(const std::exception& ex) const noexcept;

    /// <summary>
    /// return every stats that FlexCN has.
    /// </summary>
    /// <remarks>
    /// Retrieves all stats that FlexCN received from 5G core components without processing.
    /// </remarks>
    virtual void get_stats(Pistache::Http::ResponseWriter &response) = 0;
    /// <summary>
    /// Get stats for a single ue.
    /// </summary>
    /// <remarks>
    /// Retrieves all the stats that are related to a given ue, after aggregating information from mutiple sources.
    /// </remarks>
    /// <param name="ueid">id of each ue</param>
    virtual void get_stats_per_ue(const std::string &ueid, Pistache::Http::ResponseWriter &response) = 0;

    /// <summary>
    /// return every stats that FlexCN has.
    /// </summary>
    /// <remarks>
    /// Retrieves all stats that FlexCN received from 5G core components without processing.
    /// </remarks>
    virtual void trigger_subcribe(const std::string &ueid, Pistache::Http::ResponseWriter &response) = 0;

};

} // namespace oai::flexcn_server::api

#endif /* NorthBoundAPI_H_ */

