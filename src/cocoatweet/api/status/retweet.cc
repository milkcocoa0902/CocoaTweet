#include <cocoatweet/api/status/retweet.h>
#include <iostream>

namespace CocoaTweet::API::Statuses {
Retweet::Retweet() {}

void Retweet::id(const std::string& _id) {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/retweet/" + _id + ".json";
}

CocoaTweet::API::Model::Tweet Retweet::process(
    std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  CocoaTweet::API::Model::Tweet tweet;
  HttpPost::process(_oauth, [&tweet](const std::string& _rcv) {
    tweet = CocoaTweet::API::Model::Tweet(_rcv);
  });

  return tweet;
}
} // namespace CocoaTweet::API::Statuses
