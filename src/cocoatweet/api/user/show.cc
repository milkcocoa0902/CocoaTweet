#include "cocoatweet/api/user/show.h"
#include <cocoatweet/util/util.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::Users {
Show::Show() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/users/show.json";
}

void Show::screenName(const std::string& _screenName) {
  if (bodyParam_.count("user_id") > 0) {
    bodyParam_.erase("user_id");
  }
  bodyParam_.insert_or_assign("screen_name", _screenName);
}

void Show::id(const std::string& _id) {
  if (bodyParam_.count("screen_name") > 0) {
    bodyParam_.erase("screen_name");
  }
  bodyParam_.insert_or_assign("id", _id);
}

CocoaTweet::API::Model::User Show::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  CocoaTweet::API::Model::User user;
  HttpGet::process(_oauth, [&user](const std::string& _rcv) {
    user = CocoaTweet::API::Model::User::parse(_rcv);
  });
  return user;
}

} // namespace CocoaTweet::API::Users
