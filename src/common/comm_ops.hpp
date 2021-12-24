#ifndef FILE_COMM_OP_HPP_SEEN
#define FILE_COMM_OP_HPP_SEEN

#include <string>
#include <nlohmann/json.hpp>

//-----------------------------------------------------------------------------
class itti_n11_subscribe_pdu_session_status_notify {
 public:
	itti_n11_subscribe_pdu_session_status_notify()
      : http_version(1) {}
  std::string url;
  nlohmann::json json_data;
  uint8_t http_version;
};

std::size_t callback(
    const char* in, std::size_t size, std::size_t num, std::string* out);

bool subscribe_nf_event_exposure_service(
    std::shared_ptr<itti_n11_subscribe_pdu_session_status_notify> msg, const std::string& nf_name);

#endif