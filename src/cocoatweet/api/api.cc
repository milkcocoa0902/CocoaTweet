#include <cocoatweet/api/api.h>

namespace CocoaTweet::API {
API::API(CocoaTweet::OAuth::Key _key) {
  oauth_    = std::make_shared<CocoaTweet::OAuth::OAuth1>(_key);
  status_   = Statuses::Status(oauth_);
  favorite_ = Favorites::Favorite(oauth_);
  media_    = Medias::Media(oauth_);
  directMessage_ = DirectMessages::DirectMessage(oauth_);
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

DirectMessages::DirectMessage API::directMessage() const{
  return directMessage_;
}
} // namespace CocoaTweet::API
