#include "cocoatweet/api/favorite/favorite.h"
#include "cocoatweet/api/favorite/create.h"
#include "cocoatweet/api/favorite/destroy.h"

namespace CocoaTweet::API::Favorites {
Favorite::Favorite(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  oauth_ = _oauth;
}

CocoaTweet::API::Model::Tweet Favorite::create(const std::string& _id) const {
  CocoaTweet::API::Favorites::Create create;
  create.id(_id);
  return create.process(oauth_);
}

CocoaTweet::API::Model::Tweet Favorite::destroy(const std::string& _id) const {
  CocoaTweet::API::Favorites::Destroy destroy;
  destroy.id(_id);
  return destroy.process(oauth_);
}
} // namespace CocoaTweet::API::Favorites
