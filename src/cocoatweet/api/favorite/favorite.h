#ifndef COCOATWEET_API_FAVORITE_FAVORITE_H_
#define COCOATWEET_API_FAVORITE_FAVORITE_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Favorites {
class Favorite : public groupInterface {
public:
  Favorite() = default;
  Favorite(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
  void Create(const std::string& _id) const;
};
} // namespace CocoaTweet::API::Favorites

#endif
