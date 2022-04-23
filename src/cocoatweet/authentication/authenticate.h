#ifndef COCOATWEET_OAUTH_OAUTH_H_
#define COCOATWEET_OAUTH_OAUTH_H_

#include <string>
#include <map>
#include <memory>
#include "key.h"
#include <cocoatweet/authentication/authenticator.h>

namespace CocoaTweet::Authentication {
class OAuth1 : public AuthenticatorBase {
public:
  OAuth1();
  OAuth1(const Key _key);
  std::map<std::string, std::string> signature(const std::map<std::string, std::string>& _param,
                                               const std::string& _method,
                                               const std::string& _url);

  // const std::string& generateBearerToken();

  const std::string calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                        const std::string& _method, const std::string& _url);

  const std::string nonce() const;
  const std::string timestamp() const;
  const std::string method() const;
  const std::string version() const;
  std::map<std::string, std::string> oauthParam() const;
  std::string hmacSha1(std::string _key, std::string _data);
  const std::string base64(const std::string& _raw);
};
} // namespace CocoaTweet::Authentication

#endif
