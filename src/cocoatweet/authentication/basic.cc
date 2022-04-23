#include "basic.h"
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
Basic::Basic() {
  method_ = AuthenticationMethod::BASIC;
}

Basic::Basic(const Key _key){
  key_ = _key;
  method_ = AuthenticationMethod::BASIC;
}
const std::string Basic::calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                              const std::string& _method,
                                              const std::string& _url) {

  auto signature    = key_.consumerKey() + ":" + key_.consumerSecret();
  auto k64Signature = base64(signature);
  auto authHeader   = std::string("Authorization: Basic ") + k64Signature;

  return authHeader;
  
}

const std::string Basic::base64(const std::string& _raw) {
  auto base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::stringstream ss;
  for (auto r : _raw) {
    ss << std::bitset<8>(r);
  }

  if (_raw.length() % 3 == 1) {
    ss << "0000";
  } else if (_raw.length() % 3 == 2) {
    ss << "00";
  }

  auto bin           = ss.str();
  std::string base64 = "";
  for (auto i = 0; i < bin.length() / 6; i++) {
    base64 += base64Table[std::stoi(bin.substr(i * 6, 6), nullptr, 2)];
  }

  if (base64.length() % 4 == 3) {
    base64 += "=";
  } else if (base64.length() % 4 == 2) {
    base64 += "==";
  } else if (base64.length() % 4 == 1) {
    base64 += "===";
  }

  return base64;
}


} // namespace CocoaTweet::Authentication
