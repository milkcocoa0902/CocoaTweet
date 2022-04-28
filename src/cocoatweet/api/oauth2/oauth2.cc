#include <cocoatweet/api/oauth2/oauth2.h>
#include <cocoatweet/authentication/basic.h>

namespace CocoaTweet::API::OAuth2 {
OAuth2::OAuth2(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  oauth_ = _oauth;
}

const std::string OAuth2::token() const {
  //   auto key   = oauth_.lock()->key();
  //   auto oauth = std::make_shared<CocoaTweet::Authentication::Basic>(key);

  CocoaTweet::API::OAuth2::Token token;
  return token.process(oauth_);
}

const CocoaTweet::API::Model::BearerToken OAuth2::invalidateToken(
    const std::string& _bearer) const {
  //   auto key   = oauth_.lock()->key();
  //   auto oauth = std::make_shared<CocoaTweet::Authentication::Basic>(key);

  CocoaTweet::API::OAuth2::InvalidateToken invalidateToken;
  invalidateToken.accessToken(_bearer);
  return invalidateToken.process(oauth_);
}
} // namespace CocoaTweet::API::OAuth2
