#ifndef COCOATWEET_API_OAUTH1_REQUESTTOKEN_H
#define COCOATWEET_API_OAUTH1_REQUESTTOKEN_H

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/oauthToken.h>

namespace CocoaTweet::API::OAuth1 {
class RequestToken : public CocoaTweet::API::Interface::HttpPost {
public:
  RequestToken();
  void oauthCallback(const std::string& _oauthCallback);

  CocoaTweet::API::Model::OAuthToken process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);
};
} // namespace CocoaTweet::API::OAuth1

#endif