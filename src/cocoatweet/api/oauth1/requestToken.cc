#include <cocoatweet/api/oauth1/requestToken.h>
#include <cocoatweet/util/util.h>
#include <cocoatweet/authentication/oauth.h>

namespace CocoaTweet::API::OAuth1 {
RequestToken::RequestToken() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/oauth/request_token";
}

void RequestToken::oauthCallback(const std::string& _oauthCallback) {
  bodyParam_.insert_or_assign("oauth_callback", _oauthCallback);
}

CocoaTweet::API::Model::OAuthToken RequestToken::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  auto key = oauth_.lock()->key();
  key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH10A);
  auto oauth = std::make_shared<CocoaTweet::Authentication::OAuth1>(key);

  CocoaTweet::API::Model::OAuthToken oauthToken;
  HttpPost::process(oauth, [&oauthToken](const std::string& _rcv) {
    auto mp = CocoaTweet::Util::parse(_rcv, '&', '=');
    if (mp.count("oauth_token")) {
      oauthToken.oauthToken(mp.at("oauth_token"));
    }
    if (mp.count("oauth_token_secret")) {
      oauthToken.oauthTokenSecret(mp.at("oauth_token_secret"));
    }
  });
  return oauthToken;
}
} // namespace CocoaTweet::API::OAuth1