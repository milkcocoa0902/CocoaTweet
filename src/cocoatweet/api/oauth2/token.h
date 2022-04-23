#ifndef COCOATWEET_API_OAUTH2_TOKEN_H
#define COCOATWEET_API_OAUTH2_TOKEN_H

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/authentication/basic.h>

namespace CocoaTweet::API::OAuth2 {
class Token : public CocoaTweet::API::Interface::HttpPost {
public:
  Token();
  const std::string process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);
};
} // namespace CocoaTweet::API::OAuth2

#endif