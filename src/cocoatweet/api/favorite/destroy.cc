#include <cocoatweet/api/favorite/destroy.h>
#include <iostream>
namespace CocoaTweet::API::Favorites {
Destroy::Destroy() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/favorites/destroy.json";
}

void Destroy::id(const std::string& _id) {
  bodyParam_.insert_or_assign("id", _id);
}

void Destroy::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  HttpPost::process(_oauth,
                         [](const std::string& _srv) { std::cout << _srv << std::endl; });
}
} // namespace CocoaTweet::API::Favorites
