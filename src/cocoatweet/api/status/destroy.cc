#include "cocoatweet/api/status/destroy.h"
#include <iostream>
namespace CocoaTweet::API::Statuses {
Destroy::Destroy() {}
void Destroy::id(const std::string _id) {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/destroy/" + _id + ".json";
}

void Destroy::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  HttpPost::process(_oauth,
                         [](const std::string& _srv) { std::cout << _srv << std::endl; });
}

} // namespace CocoaTweet::API::Statuses
