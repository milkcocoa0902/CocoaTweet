#ifndef COCOATWEET_API_OAUTH1_INVALIDATETOKEN_H_
#define COCOATWEET_API_OAUTH1_INVALIDATETOKEN_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/oauthToken.h>
namespace CocoaTweet::API::OAuth1 {
class InvalidateToken : public CocoaTweet::API::Interface::HttpPost {
private:
public:
  InvalidateToken();

  const CocoaTweet::API::Model::OAuthToken process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);
};
} // namespace CocoaTweet::API::OAuth1

#endif