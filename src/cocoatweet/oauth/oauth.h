#ifndef COCOATWEET_OAUTH_OAUTH_H_
#define COCOATWEET_OAUTH_OAUTH_H_

#include <string>
#include <map>
#include <memory>
#include "key.h"

namespace CocoaTweet::OAuth {
class OAuth1 {
public:

  enum AuthType{
    OAuth,
    Bearer
  };

  OAuth1();
  OAuth1(const Key _key);
  std::map<std::string, std::string> signature(const std::map<std::string, std::string>& _param,
                                               const std::string& _method,
                                               const std::string& _url);
  
  const std::string& generateBearerToken();
  const std::string calculateAuthHeader(std::map<std::string, std::string> _bodyParam, const std::string& _method, const std::string& _url);


  const std::string nonce() const;
  const std::string timestamp() const;
  const std::string method() const;
  const std::string version() const;
  const Key key() const;
  std::map<std::string, std::string> oauthParam() const;
  std::string hmacSha1(std::string _key, std::string _data);
  const std::string base64(const std::string& _raw);

private:
  AuthType authType_;
  Key key_;
  const std::string SIGNATURE_METHOD_ = "HMAC-SHA1";
  const std::string OAUTH_VERSION_    = "1.0";
  static size_t curlCallback_(char* _ptr, size_t _size, size_t _nmemb, std::string* _stream) {
    int realsize = _size * _nmemb;
    _stream->append(_ptr, realsize);
    return realsize;
  }

};
} // namespace CocoaTweet::OAuth

#endif
