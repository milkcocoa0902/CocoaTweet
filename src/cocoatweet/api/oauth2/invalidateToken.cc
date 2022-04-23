#include <cocoatweet/api/oauth2/invalidateToken.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::OAuth2 {
InvalidateToken::InvalidateToken() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/oauth2/invalidate_token";
}

void InvalidateToken::accessToken(const std::string _bearer) {
  // bodyParam_.insert_or_assign("access_token", _bearer);
  bearer_ = _bearer;
}

const CocoaTweet::API::Model::BearerToken InvalidateToken::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  auto org   = url_;
  auto url   = url_ + "?access_token=" + bearer_;
  url_       = url;
  auto basic = std::make_shared<CocoaTweet::Authentication::Basic>(_oauth.lock()->key());
  CocoaTweet::API::Model::BearerToken bearer;
  HttpPost::process(basic, [&bearer](const std::string& _rcv) {
    auto j = nlohmann::json::parse(_rcv);
    bearer.token(j["access_token"]);
  });
  url_ = org;
  return bearer;
}

} // namespace CocoaTweet::API::OAuth2