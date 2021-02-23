#include "cocoatweet/api/status/destroy.h"
#include <cocoatweet/api/model/tweet.h>
#include <iostream>
namespace CocoaTweet::API::Statuses {
Destroy::Destroy() {}
void Destroy::id(const std::string _id) {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/destroy/" + _id + ".json";
}

void Destroy::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  CocoaTweet::API::Model::Tweet tweet;
  HttpPost::process(_oauth, [&tweet](const std::string& _srv) {
    tweet = CocoaTweet::API::Model::Tweet::parse(100, _srv);
  });
  std::cout << "afw" << std::endl;
}

} // namespace CocoaTweet::API::Statuses
