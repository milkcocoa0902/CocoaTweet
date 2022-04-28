#include "oauthToken.h"

namespace CocoaTweet::API::Model {

OAuthToken::OAuthToken() : oauthToken_(""), oauthTokenSecret_("") {}
OAuthToken::OAuthToken(const std::string _oauthToken, const std::string& _oauthTokenSecret)
    : oauthToken_(_oauthToken), oauthTokenSecret_(_oauthTokenSecret) {}
const std::string& OAuthToken::oauthToken() const {
  return oauthToken_;
}
const std::string& OAuthToken::oauthTokenSecret() const {
  return oauthTokenSecret_;
}
void OAuthToken::oauthToken(const std::string& _oauthToken) {
  oauthToken_ = _oauthToken;
}
void OAuthToken::oauthTokenSecret(const std::string& _oauthTokenSecret) {
  oauthTokenSecret_ = _oauthTokenSecret;
}
} // namespace CocoaTweet::API::Model