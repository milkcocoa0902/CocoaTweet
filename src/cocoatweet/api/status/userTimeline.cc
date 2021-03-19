#include "cocoatweet/api/status/userTimeline.h"
#include <cocoatweet/util/util.h>
#include "nlohmann/json.hpp"
#include <iostream>

namespace CocoaTweet::API::Statuses {
UserTimeline::UserTimeline() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/user_timeline.json";
}

void UserTimeline::screenName(const std::string& _screenName) {
  bodyParam_.insert_or_assign("screen_name", _screenName);
}

std::vector<CocoaTweet::API::Model::Tweet> UserTimeline::process(
    std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  std::vector<CocoaTweet::API::Model::Tweet> tweet;
  HttpGet::process(_oauth, [&tweet](const std::string& _rcv) {
    auto json = nlohmann::json::parse(_rcv);
    for (auto j : json) {
      tweet.push_back(CocoaTweet::API::Model::Tweet::parse(j.dump()));
      std::cout << j.dump() << std::endl;
    }
  });
  return tweet;
}

} // namespace CocoaTweet::API::Statuses
