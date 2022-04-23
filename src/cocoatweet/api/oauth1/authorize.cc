#include <string>
#include <cocoatweet/api/oauth1/authorize.h>
#include <iostream>
#include <cocoatweet/util/util.h>

namespace CocoaTweet::API::OAuth1 {
Authorize::Authorize() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/oauth/authorize";
}

void Authorize::oauthToken(const std::string& _oauthToken) {
  bodyParam_.insert_or_assign("oauth_token", _oauthToken);
}

void Authorize::forceLogin(const bool _forceLogin) {
  bodyParam_.insert_or_assign("force_login", std::to_string(static_cast<int>(_forceLogin)));
}

void Authorize::screenName(const std::string& _screenName) {
  bodyParam_.insert_or_assign("screen_name", _screenName);
}

const std::string Authorize::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> __unused__) {
  std::vector<std::string> tmp;
  std::string query = "";
  for (const auto& [key, value] : bodyParam_) {
    tmp.push_back(key + "=" + value);
    query = CocoaTweet::Util::join(tmp, "&");
  }
  return url_ + "?" + query;
  ;
}
} // namespace CocoaTweet::API::OAuth1