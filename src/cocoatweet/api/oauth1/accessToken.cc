#include <cocoatweet/api/oauth1/accessToken.h>
#include <cocoatweet/util/util.h>
#include <iostream>

#include <cocoatweet/authentication/oauth.h>
namespace CocoaTweet::API::OAuth1 {
AccessToken::AccessToken() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/oauth/access_token";
}

void AccessToken::oauthVerifier(const std::string& _verifier) {
  bodyParam_.insert_or_assign("oauth_verifier", _verifier);
}

void AccessToken::oauthToken(const CocoaTweet::API::Model::OAuthToken _token) {
  oauthToken_ = _token;
}

const CocoaTweet::API::Model::OAuthToken AccessToken::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {

  auto key = oauth_.lock()->key();
  key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH10A);
  key.accessToken(oauthToken_.oauthToken());
  key.accessTokenSecret(oauthToken_.oauthTokenSecret());
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
    std::cout << _rcv << std::endl;
  });
  return oauthToken;
}
} // namespace CocoaTweet::API::OAuth1