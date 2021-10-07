#include <cocoatweet/api/model/user.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::Model {
CocoaTweet::API::Model::User User::parse(const std::string& _json) {
  auto j = nlohmann::json::parse(_json);
  User user;

  user.id(j["id_str"]);
  return user;
}

void User::id(const std::string& _id) {
  id_ = _id;
}

void User::name(const std::string& _name) {
  name_ = _name;
}

void User::screenName(const std::string& _screen) {
  screenName_ = _screen;
}

void User::location(const std::string& _location) {
  location_ = _location;
}

const std::string& User::id() const {
  return id_;
}

} // namespace CocoaTweet::API::Model
