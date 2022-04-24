#include <cocoatweet/api/api.h>
#include <cocoatweet/authentication/oauth.h>
#include <cocoatweet/authentication/bearer.h>
#include <cocoatweet/authentication/plain.h>

namespace CocoaTweet::API {
API::API(CocoaTweet::Authentication::Key _key) {
  swapKey(_key);
}

void API::swapKey(const CocoaTweet::Authentication::Key _key) {
  if (_key.authType() == CocoaTweet::Authentication::Key::OAUTH10A) {
    oauth_ = std::make_shared<CocoaTweet::Authentication::OAuth1>(_key);
  } else if (_key.authType() == CocoaTweet::Authentication::Key::OAUTH2) {
    oauth_ = std::make_shared<CocoaTweet::Authentication::Bearer>(_key);
  }
  user_          = Users::User(oauth_);
  status_        = Statuses::Status(oauth_);
  favorite_      = Favorites::Favorite(oauth_);
  media_         = Medias::Media(oauth_);
  directMessage_ = DirectMessages::DirectMessage(oauth_);
  oauth1_        = OAuth1::OAuth(oauth_);
  oauth2_        = OAuth2::OAuth2(oauth_);
}

// const std::string& API::generateBearerToken() const {
//   return oauth_->generateBearerToken();
// }

Users::User API::user() const {
  return user_;
}

Statuses::Status API::status() const {
  return status_;
}

Favorites::Favorite API::favorite() const {
  return favorite_;
}

Medias::Media API::media() const {
  return media_;
}

DirectMessages::DirectMessage API::directMessage() const {
  return directMessage_;
}
OAuth1::OAuth API::oauth1() const {
  return oauth1_;
}
OAuth2::OAuth2 API::oauth2() const {
  return oauth2_;
}
} // namespace CocoaTweet::API
