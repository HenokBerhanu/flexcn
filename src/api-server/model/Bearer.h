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
 * Bearer.h
 *
 * 
 */

#ifndef Bearer_H_
#define Bearer_H_


#include <string>
#include <nlohmann/json.hpp>


namespace oai {
namespace flexcn_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  Bearer
{
public:
    Bearer();
    virtual ~Bearer() = default;


    /// <summary>
    /// Validate the current data in the model. Throws a ValidationException on failure.
    /// </summary>
    void validate() const;

    /// <summary>
    /// Validate the current data in the model. Returns false on error and writes an error
    /// message into the given stringstream.
    /// </summary>
    bool validate(std::stringstream& msg) const;

    bool operator==(const Bearer& rhs) const;
    bool operator!=(const Bearer& rhs) const;

    /////////////////////////////////////////////
    /// Bearer members

    /// <summary>
    /// 
    /// </summary>
    int64_t getEpsBearerId() const;
    void setEpsBearerId(int64_t const value);

    int64_t getEpsMeterId() const;
    void setEpsMeterId(int64_t const value);
    bool epsMeterIdIsSet() const;
    void unsetEpsMeterId();
    
    /// <summary>
    /// (optional) Slice ID.
    /// </summary>
    int64_t getSliceId() const;
    void setSliceId(int64_t const value);
    bool sliceIdIsSet() const;
    void unsetSlice_id();
    /// <summary>
    /// (optional) Type of service including DSCP and ECN.
    /// </summary>
    int64_t getTos() const;
    void setTos(int64_t const value);
    bool tosIsSet() const;
    void unsetTos();
    /// <summary>
    /// 
    /// </summary>
    std::string getImsi() const;
    void setImsi(std::string const& value);
    /// <summary>
    /// S1 downlink tunnel ID
    /// </summary>
    std::string getS1UlTeid() const;
    void setS1UlTeid(std::string const& value);
    /// <summary>
    /// S1 uplink tunnel ID
    /// </summary>
    std::string getS1DlTeid() const;
    void setS1DlTeid(std::string const& value);
    /// <summary>
    /// IP address of UE
    /// </summary>
    std::string getUeIp() const;
    void setUeIp(std::string const& value);
    /// <summary>
    /// IP address of eNodeB
    /// </summary>
    std::string getEnbIp() const;
    void setEnbIp(std::string const& value);

    friend void to_json(nlohmann::json& j, const Bearer& o);
    friend void from_json(const nlohmann::json& j, Bearer& o);
protected:
    int64_t m_Eps_bearer_id;
    int64_t m_Eps_meter_id; // eps_meter_id
    bool m_Eps_meter_idIsSet;
    int64_t m_Slice_id;
    bool m_Slice_idIsSet;
    int64_t m_Tos;
    bool m_TosIsSet;
    std::string m_Imsi;

    std::string m_S1_ul_teid;

    std::string m_S1_dl_teid;

    std::string m_Ue_ip;

    std::string m_Enb_ip;


    // Helper overload for validate. Used when one model stores another model and calls it's validate.
    bool validate(std::stringstream& msg, const std::string& pathPrefix) const;
};

}  // namespace api
}  // namespace flexcn_server
}  // namespace oai

#endif /* Bearer_H_ */