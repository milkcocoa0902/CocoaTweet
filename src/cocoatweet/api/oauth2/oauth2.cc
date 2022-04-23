#include <cocoatweet/api/oauth2/oauth2.h>
#include <cocoatweet/authentication/basic.h>

namespace CocoaTweet::API::OAuth2 {
OAuth2::OAuth2(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  oauth_ = _oauth;
}

const std::string OAuth2::token() const {
  auto key   = oauth_.lock()->key();
  auto oauth = std::make_shared<CocoaTweet::Authentication::Basic>(key);

  CocoaTweet::API::OAuth2::Token token;
  return token.process(oauth);
}
} // namespace CocoaTweet::API::OAuth2
