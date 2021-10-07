#include <cocoatweet/api/model/user.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::Model {
CocoaTweet::API::Model::User User::parse(const std::string& _json) {
  auto j = nlohmann::json::parse(_json);
  User user;

  user.id(j["id_str"]);
  user.name(j["name"]);
  user.screenName(j["screen_name"]);
  if (j["location"].is_null() == false) {
    user.location(j["location"]);
  }

  if (j["url"].is_null() == false) {
    user.location(j["url"]);
  }

  if (j["description"].is_null() == false) {
    user.location(j["description"]);
  }

  user.protectedUser(j["protected"]);
  user.follower(j["followers_count"]);
  user.follow(j["friends_count"]);
  user.listed(j["listed_count"]);
  user.favorite(j["favourites_count"]);
  if (j["profile_banner_url"].is_null() == false) {
    user.bannerUrl(j["profile_banner_url"]);
  }
  if (j["profile_image_url_https"].is_null() == false) {
    user.iconUrl(j["profile_image_url_https"]);
  }

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
void User::url(const std::string& _url) {
  url_ = _url;
}
void User::description(const std::string& _description) {
  description_ = _description;
}

void User::protectedUser(const bool _protected) {
  protectedUser_ = _protected;
}
void User::follower(const long _follower) {
  follower_ = _follower;
}
void User::follow(const long _follow) {
  follow_ = _follow;
}
void User::listed(const long _listed) {
  listed_ = _listed;
}
void User::favorite(const long _favorite) {
  favorite_ = _favorite;
}
void User::createdAt(const std::string& _created) {
  createdAt_ = _created;
}
void User::bannerUrl(const std::string& _banner) {
  bannerUrl_ = _banner;
}
void User::iconUrl(const std::string& _icon) {
  iconUrl_ = _icon;
}

const std::string& User::id() const {
  return id_;
}

const std::string& User::name() const {
  return name_;
}
const std::string& User::screenName() const {
  return screenName_;
}
const std::string& User::location() const {
  return location_;
}
const std::string& User::url() const {
  return url_;
}
const std::string& User::description() const {
  return description_;
}
bool User::protectedUser() const {
  return protectedUser_;
}
long User::follower() const {
  return follower_;
}
long User::follow() const {
  return follow_;
}
long User::listed() const {
  return listed_;
}
long User::favorite() const {
  return favorite_;
}
const std::string& User::created() const {
  return createdAt_;
}
const std::string& User::bannerUrl() const {
  return bannerUrl_;
}
const std::string& User::icon() const {
  return iconUrl_;
}

} // namespace CocoaTweet::API::Model
