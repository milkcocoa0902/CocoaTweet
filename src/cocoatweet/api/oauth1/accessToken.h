#ifndef COCOATWEET_API_OAUTH1_ACCESSTOKEN_H_
#define COCOATWEET_API_OAUTH1_ACCESSTOKEN_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/oauthToken.h>
namespace CocoaTweet::API::OAuth1 {
class AccessToken : public CocoaTweet::API::Interface::HttpPost {
private:
  CocoaTweet::API::Model::OAuthToken oauthToken_;

public:
  AccessToken();

  void oauthVerifier(const std::string& _verifier);
  void oauthToken(const CocoaTweet::API::Model::OAuthToken _token);

  const CocoaTweet::API::Model::OAuthToken process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);
};
} // namespace CocoaTweet::API::OAuth1

#endif