#include "cocoatweet/api/status/update.h"
#include <iostream>

namespace CocoaTweet::API::Statuses {
Update::Update() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/update.json";
}
void Update::status(const std::string _status) {
  status_ = _status;
  bodyParam_.insert_or_assign("status", status_);
}

void Update::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  HttpPost::process(_oauth,
                         [](const std::string& _srv) { std::cout << _srv << std::endl; });
}

} // namespace CocoaTweet::API::Statuses
