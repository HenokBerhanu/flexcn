#include "logger.hpp"
#include "comm_ops.hpp"
#include "flexcn.h"

#include <curl/curl.h>

#define NRF_CURL_TIMEOUT_MS 100L

//------------------------------------------------------------------------------
// To read content of the response from NF
std::size_t callback(
    const char* in, std::size_t size, std::size_t num, std::string* out) {
  const std::size_t totalBytes(size * num);
  out->append(in, totalBytes);
  return totalBytes;
}


bool subscribe_nf_event_exposure_service(
    std::shared_ptr<itti_n11_subscribe_pdu_session_status_notify> msg, const std::string& nf_name) {
  Logger::flexcn_sbi().debug(
      "Send message to %s to be notified when a new event happens", nf_name.c_str());

  Logger::flexcn_sbi().debug(
      "Send msg to %s, %s URL %s", nf_name.c_str(), nf_name.c_str(),
      msg->url.c_str());

  std::string body = msg->json_data.dump();
  Logger::flexcn_sbi().debug(
      "Send msg to %s, msg body: %s", nf_name.c_str(),
      body.c_str());

  curl_global_init(CURL_GLOBAL_ALL);
  CURL* curl = curl = curl_easy_init();

  bool return_res = false;

  if (curl) {
    CURLcode res               = {};
    struct curl_slist* headers = nullptr;
    // headers = curl_slist_append(headers, "charsets: utf-8");
    headers = curl_slist_append(headers, "content-type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, msg->url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, NRF_CURL_TIMEOUT_MS);

    if (msg->http_version == 2) {
      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
      // we use a self-signed test server, skip verification during debugging
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
      curl_easy_setopt(
          curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE);
    }

    // Response information.
    long httpCode = {0};
    std::unique_ptr<std::string> httpData(new std::string());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    Logger::flexcn_sbi().debug(
        "Msg, response from %s, HTTP Code: %d",
        nf_name.c_str(), httpCode);

    if ((static_cast<http_response_codes_e>(httpCode) ==
         http_response_codes_e::HTTP_RESPONSE_CODE_CREATED) or
        (static_cast<http_response_codes_e>(httpCode) ==
         http_response_codes_e::HTTP_RESPONSE_CODE_NO_CONTENT)) {
      Logger::flexcn_sbi().debug(
          "Msg, got successful response from %s", nf_name.c_str());
      return_res = true;

    } else {
      Logger::flexcn_sbi().warn(
          "Msg, could not get response from %s", nf_name.c_str());
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return return_res;
}
