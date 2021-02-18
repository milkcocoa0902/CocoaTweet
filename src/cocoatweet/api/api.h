#ifndef COCOATWEET_API_H_
#define COCOATWEET_API_H_

#include "cocoatweet/api/status/status.h"
#include "cocoatweet/api/favorite/favorite.h"
#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API {
class API {
public:
  API(CocoaTweet::OAuth::Key _key);
  Statuses::Status status() const;
  Favorites::Favorite favorite() const;

private:
  Statuses::Status status_;
  Favorites::Favorite favorite_;
  std::shared_ptr<CocoaTweet::OAuth::OAuth1> oauth_;
};
} // namespace CocoaTweet::API

#endif
