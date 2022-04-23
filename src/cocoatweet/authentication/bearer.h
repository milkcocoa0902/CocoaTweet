#ifndef COCOATWEET_AUTHENTICATION_BEARER_H_
#define COCOATWEET_AUTHENTICATION_BEARER_H_

#include <string>
#include <map>
#include <memory>
#include "key.h"
#include <cocoatweet/authentication/authenticator.h>

namespace CocoaTweet::Authentication {
class Bearer : public AuthenticatorBase {
public:
  Bearer();
  Bearer(const Key _key);

  const std::string calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                        const std::string& _method, const std::string& _url);
};
} // namespace CocoaTweet::Authentication

#endif
