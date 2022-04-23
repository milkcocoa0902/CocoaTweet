#include "bearer.h"
#include "cocoatweet/util/util.h"
#include <random>
#include <ctime>
#include <bitset>
#include <sstream>
#include <string>
#include <cstring>
#include <iterator>
#include <nlohmann/json.hpp>

#include <cocoatweet/exception/invalidParameterException.h>

extern "C" {
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <openssl/buffer.h>
#include <curl/curl.h>
}

#ifndef NDEBUG
#include <iostream>
#endif

namespace CocoaTweet::Authentication {
Bearer::Bearer() {
  method_ = AuthenticationMethod::OAUTH2;
}

Bearer::Bearer(const Key _key) {
  key_    = _key;
  method_ = AuthenticationMethod::OAUTH2;
}
const std::string Bearer::calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                              const std::string& _method,
                                              const std::string& _url) {
  auto authHeader = std::string("Authorization: Bearer ") + key_.bearerToken();

  return authHeader;
}

} // namespace CocoaTweet::Authentication
