#include <cocoatweet/api/model/tweet.h>
#include <cocoatweet/exception/tweetNotFoundException.h>
#include <cocoatweet/exception/authenticateException.h>
#include <cocoatweet/exception/tweetDuplicateException.h>
#include <cocoatweet/exception/tweetTooLongException.h>
#include <cocoatweet/exception/rateLimitException.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::Model {
Tweet Tweet::parse(const unsigned int _responseCode, const std::string& _json) {
  auto j = nlohmann::json::parse(_json);
  Tweet tweet;

  if (_responseCode == 200) {
    tweet.id(j["id_str"]);
		tweet.createdAt(j["created_at"]);
		tweet.text(j["text"]);
		tweet.source(j["source"]);
  } else {
    auto error   = j["errors"][0]["code"];
    auto message = j["errors"][0]["message"];
    if (error.get<int>() == 144) {
      throw CocoaTweet::Exception::TweetNotFoundException(message.get<std::string>().c_str());
    }else if(error.get<int>() == 32){
      throw CocoaTweet::Exception::AuthenticateException(message.get<std::string>().c_str());
    }else if(error.get<int>() == 187){
      throw CocoaTweet::Exception::TweetDuplicateException(message.get<std::string>().c_str());
    }else if(error.get<int>() == 88 || error.get<int>() == 185){
      throw CocoaTweet::Exception::RateLimitException(message.get<std::string>().c_str());
    }else if(error.get<int>() == 186){
      throw CocoaTweet::Exception::TweetTooLongException(message.get<std::string>().c_str());
    }
  }

  return tweet;
}

void Tweet::id(const std::string _id) {
  id_ = _id;
}

void Tweet::createdAt(const std::string _at){
  createdAt_ = _at;
}

void Tweet::text(const std::string _text){
  text_ = _text;
}
void Tweet::source(const std::string _source){
  source_ = _source;
}

const std::string Tweet::id() const {
  return id_;
}
const std::string Tweet::createdAt() const {
  return createdAt_;
}
const std::string Tweet::text() const {
  return text_;
}
const std::string Tweet::source() const {
  return source_;
}
} // namespace CocoaTweet::API::Model
