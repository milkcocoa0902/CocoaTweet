#include "oauth.h"
#include "cocoatweet/util/util.h"
#include <random>
#include <ctime>
#include <bitset>
#include <sstream>
#include <string>
#include <cstring>
#include <iterator>
#include <iostream>

extern "C" {
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <openssl/buffer.h>
}

namespace CocoaTweet::OAuth {
OAuth1::OAuth1() {}

OAuth1::OAuth1(const Key _key) : key_(_key) {}

std::map<std::string, std::string> OAuth1::signature(
    const std::map<std::string, std::string>& _param, const std::string& _method,
    const std::string& _url) {
  std::vector<std::string> tmp;
  for (const auto& [key, value] : _param) {
    tmp.push_back(key + "=" + value);
    std::cout << (key + "=" + value) << std::endl;
  }

  std::string query = CocoaTweet::Util::join(tmp, "&");

  auto significateKey  = key().consumerSecret() + "&" + key().accessTokenSecret();
  auto significateBase = _method + "&" + CocoaTweet::Util::urlEncode(_url) + "&" +
                         CocoaTweet::Util::urlEncode(query);
  auto k64Sha1 = hmacSha1(significateKey, significateBase);

  std::cout << "significate key : " << significateKey << std::endl;
  std::cout << "significate base : " << significateBase << std::endl;
  std::cout << "hmac-sha1 : " << k64Sha1 << std::endl;

  auto ret = std::map<std::string, std::string>{{"oauth_signature", k64Sha1}};
  return ret;
}

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
  return SIGNATURE_METHOD_;
}

const std::string OAuth1::version() const {
  return OAUTH_VERSION_;
}

const Key OAuth1::key() const {
  return key_;
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

} // namespace CocoaTweet::OAuth
