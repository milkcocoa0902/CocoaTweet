#include <cocoatweet/api/favorite/destroy.h>

namespace CocoaTweet::API::Favorites {
Destroy::Destroy() {
  url_ = "https://api.twitter.com/1.1/favorites/destroy.json";
}

void Destroy::id(const std::string& _id) {
  bodyParam_.insert_or_assign("id", _id);
}
} // namespace CocoaTweet::API::Favorites
