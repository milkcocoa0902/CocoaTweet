#include <cocoatweet/api/favorite/create.h>

namespace CocoaTweet::API::Favorites {
Create::Create() {
  url_ = "https://api.twitter.com/1.1/favorites/create.json";
}

void Create::id(const std::string& _id) {
  bodyParam_.insert_or_assign("id", _id);
}
} // namespace CocoaTweet::API::Favorites
