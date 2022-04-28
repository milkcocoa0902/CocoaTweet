#ifndef COCOATWEET_API_OAUTH2_INVALIDATETOKEN_H_
#define COCOATWEET_API_OAUTH2_INVALIDATETOKEN_H_

#include <cocoatweet/api/model/bearerToken.h>
#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/authentication/basic.h>

namespace CocoaTweet::API::OAuth2 {
class InvalidateToken : public CocoaTweet::API::Interface::HttpPost {
public:
  InvalidateToken();
  void accessToken(const std::string _bearer);
  const CocoaTweet::API::Model::BearerToken process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

private:
  std::string bearer_;
};
} // namespace CocoaTweet::API::OAuth2

#endif