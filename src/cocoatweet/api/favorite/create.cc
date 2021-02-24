#include <cocoatweet/api/favorite/create.h>
#include <iostream>
namespace CocoaTweet::API::Favorites {
Create::Create() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/favorites/create.json";
}

void Create::id(const std::string& _id) {
  bodyParam_.insert_or_assign("id", _id);
}

void Create::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  HttpPost::process(_oauth, [](const unsigned int _, const std::string& _srv) { std::cout << _srv << std::endl; });
}
} // namespace CocoaTweet::API::Favorites
