#include <cocoatweet/api/oauth1/invalidateToken.h>
#include <cocoatweet/util/util.h>
#include "nlohmann/json.hpp"

#include <cocoatweet/authentication/oauth.h>
#include <iostream>

namespace CocoaTweet::API::OAuth1 {
InvalidateToken::InvalidateToken() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/oauth/invalidate_token";
}

const CocoaTweet::API::Model::OAuthToken InvalidateToken::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  auto key = _oauth.lock()->key();
  key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH10A);
  auto oauth = std::make_shared<CocoaTweet::Authentication::OAuth1>(key);
  CocoaTweet::API::Model::OAuthToken oauthToken;
  HttpPost::process(oauth, [&oauthToken](const std::string& _rcv) {
      std::cout << _rcv << std::endl;
    auto j = nlohmann::json::parse(_rcv);
      oauthToken.oauthToken(j["access_token"]);
  });
  return oauthToken;
}
} // namespace CocoaTweet::API::OAuth1