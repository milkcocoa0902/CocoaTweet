#ifndef COCOATWEET_AUTHENTICATION_BASIC_H_
#define COCOATWEET_AUTHENTICATION_BASIC_H_

#include <string>
#include <map>
#include <memory>
#include "key.h"
#include <cocoatweet/authentication/authenticator.h>

namespace CocoaTweet::Authentication {
class Basic : public AuthenticatorBase {
public:
  Basic();
  Basic(const Key _key);

  // const std::string& generateBearerToken();

  const std::string calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                        const std::string& _method, const std::string& _url);
  const std::string base64(const std::string& _raw);
};
} // namespace CocoaTweet::Authentication

#endif
