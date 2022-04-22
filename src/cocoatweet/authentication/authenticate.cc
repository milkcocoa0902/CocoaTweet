#include "authenticate.h"
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
OAuth1::OAuth1() {
  method_ = AuthenticationMethod::OAUTH10A;
}

OAuth1::OAuth1(const Key _key){
  key_ = _key;
  method_ = AuthenticationMethod::OAUTH10A;
}

std::map<std::string, std::string> OAuth1::signature(
    const std::map<std::string, std::string>& _param, const std::string& _method,
    const std::string& _url) {
  std::vector<std::string> tmp;
  for (const auto& [key, value] : _param) {
    tmp.push_back(key + "=" + value);
  }

  std::string query = CocoaTweet::Util::join(tmp, "&");

  auto significateKey  = key().consumerSecret() + "&" + key().accessTokenSecret();
  auto significateBase = _method + "&" + CocoaTweet::Util::urlEncode(_url) + "&" +
                         CocoaTweet::Util::urlEncode(query);
  auto k64Sha1 = hmacSha1(significateKey, significateBase);

  auto ret = std::map<std::string, std::string>{{"oauth_signature", k64Sha1}};
  return ret;
}

const std::string OAuth1::calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                              const std::string& _method,
                                              const std::string& _url) {
  auto authParam   = oauthParam();
  auto sigingParam = authParam;
  if (!_bodyParam.empty()) {
    for (const auto [k, v] : _bodyParam) {
      sigingParam.insert_or_assign(k, v);
    }
  }

  auto sign = signature(sigingParam, _method, _url);

  authParam.merge(sign);
  // ヘッダの構築
  std::string oauthHeader = "authorization: OAuth ";
  {
    std::vector<std::string> tmp;
    for (const auto& [key, value] : authParam) {
      tmp.push_back(key + "=" + CocoaTweet::Util::urlEncode(value));
    }
    oauthHeader += CocoaTweet::Util::join(tmp, ",");
  }

  return oauthHeader;
}


// const std::string& OAuth1::generateBearerToken() {
//   auto signature    = key_.consumerKey() + ":" + key_.consumerSecret();
//   auto k64Signature = base64(signature);
//   auto authHeader   = std::string("Authorization: Basic ") + k64Signature;
//   auto contentType =
//       std::string("Content-Type: application/x-www-form-urlencoded;charset=UTF-8");
//   auto url         = std::string("https://api.twitter.com/oauth2/token");
//   auto requestBody = std::string("grant_type=client_credentials");

//   // do post
//   CURL* curl;
//   CURLcode res;
//   std::string rcv;
//   long responseCode;
//   curl = curl_easy_init();
//   if (curl) {
//     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//     curl_easy_setopt(curl, CURLOPT_POST, 1);
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestBody.length());
//     curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback_);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (std::string*)&rcv);
// #ifndef NDEBUG
//     std::cout << "requestBody : " << requestBody << std::endl;
//     curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
// #endif
//     // Headerを保持するcurl_slist*を初期化
//     struct curl_slist* headers = NULL;
//     // Authorizationをヘッダに追加
//     headers = curl_slist_append(headers, authHeader.c_str());
//     headers = curl_slist_append(headers, contentType.c_str());
//     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//     res = curl_easy_perform(curl);
//     curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
//     curl_easy_cleanup(curl);
//   }
//   if (res != CURLE_OK) {
//     throw std::runtime_error(std::string("INTERNAL ERROR : curl(") + std::to_string(res) + ")");
//     exit(1);
//   }

//   auto j = nlohmann::json::parse(rcv);
//   if ((responseCode / 100) == 4) {
//     auto error   = j["errors"][0]["code"];
//     auto message = j["errors"][0]["message"];
//     if (j.count("error") != 0) {
//       // この形式はエラーコードを持たないのでエラー種別が特定できない
//       throw new CocoaTweet::Exception::Exception(j["error"]);
//     }
//     if (error.get<int>() == 44) {
//       throw CocoaTweet::Exception::InvalidParameterException(
//           message.get<std::string>().c_str());
//     }
//   }

//   key_.bearerToken(j["access_token"]);
//   authType_ = AuthType::Bearer;
//   return key_.bearerToken();
// }

const std::string OAuth1::nonce() const {
  std::random_device engine;
  std::string nonceTable = "abcdefghijklmnopqrstuvwxyz0123456789";
  std::uniform_int_distribution<std::size_t> dist(0, nonceTable.length() - 1);
  std::string nonce;

  for (auto i = 0; i < 32; ++i) {
    nonce += nonceTable[dist(engine)];
  }

  return nonce;
}

const std::string OAuth1::timestamp() const {
  return std::to_string(time(nullptr));
}

const std::string OAuth1::method() const {
  return "HMAC-SHA1";
}

const std::string OAuth1::version() const {
  return "1.0";
}


std::map<std::string, std::string> OAuth1::oauthParam() const {
  auto tmp = std::map<std::string, std::string>{{"oauth_nonce", nonce()},
                                                {"oauth_signature_method", method()},
                                                {"oauth_timestamp", timestamp()},
                                                {"oauth_version", version()}};
  tmp.merge(key().noSecret());

  return tmp;
}

const std::string OAuth1::base64(const std::string& _raw) {
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

std::string OAuth1::hmacSha1(std::string _key, std::string _data) {
  unsigned char result[255];
  unsigned int length = 255;

  HMAC(EVP_sha1(), reinterpret_cast<const unsigned char*>(_key.c_str()), _key.length(),
       reinterpret_cast<const unsigned char*>(_data.c_str()), _data.length(), result, &length);

  auto sha1 = std::string(reinterpret_cast<char*>(result), length);

  // base64 encodeもやっちゃえ日産
  BIO* encoder = BIO_new(BIO_f_base64());
  BIO* bmem    = BIO_new(BIO_s_mem());
  encoder      = BIO_push(encoder, bmem);
  BIO_write(encoder, sha1.c_str(), sha1.length());
  BIO_flush(encoder);

  BUF_MEM* bptr;
  BIO_get_mem_ptr(encoder, &bptr);

  char* k64 = (char*)std::malloc(bptr->length);
  std::memcpy(k64, bptr->data, bptr->length - 1);
  k64[bptr->length - 1] = 0;

  BIO_free_all(encoder);

  return static_cast<std::string>(k64);
}

} // namespace CocoaTweet::Authentication
