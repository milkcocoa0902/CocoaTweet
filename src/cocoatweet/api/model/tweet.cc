#include <cocoatweet/api/model/tweet.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::Model {
Tweet Tweet::parse(const std::string& _json) {
		auto j = nlohmann::json::parse(_json);
  Tweet tweet;

  tweet.id(j["id_str"]);
  tweet.createdAt(j["created_at"]);
  tweet.text(j["text"]);
  tweet.source(j["source"]);

 tweet.user(CocoaTweet::API::Model::User(j["user"].dump()));

  return tweet;
}

void Tweet::id(const std::string _id) {
  id_ = _id;
}

void Tweet::createdAt(const std::string _at) {
  createdAt_ = _at;
}

void Tweet::text(const std::string _text) {
  text_ = _text;
}
void Tweet::source(const std::string _source) {
  source_ = _source;
}

void Tweet::user(const CocoaTweet::API::Model::User _user) {
  user_ = _user;
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

const CocoaTweet::API::Model::User Tweet::user() const {
  return user_;
}
} // namespace CocoaTweet::API::Model
