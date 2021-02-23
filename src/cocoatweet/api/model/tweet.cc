#include <cocoatweet/api/model/tweet.h>
#include <cocoatweet/exception/tweetNotFoundException.h>
#include "nlohmann/json.hpp"

#include <iostream>

namespace CocoaTweet::API::Model {
Tweet Tweet::parse(const unsigned int _responseCode, const std::string& _json) {
  auto j = nlohmann::json::parse(_json);
  Tweet tweet;

  if (_responseCode == 200) {
    Tweet tweet;
    tweet.id(j["id_str"]);
  } else {
    auto error   = j["errors"][0]["code"];
    auto message = j["errors"][0]["message"];
    if (error.get<int>() == 144) {
      throw CocoaTweet::Exception::TweetNotFoundException(message.get<std::string>().c_str());
    }
  }

  return tweet;
}

void Tweet::id(const std::string& _id) {
  id_ = _id;
}

const std::string& Tweet::id() const {
  return id_;
}
} // namespace CocoaTweet::API::Model
