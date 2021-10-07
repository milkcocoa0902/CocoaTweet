#ifndef COCOATWEET_API_MODEL_USER_H_
#define COCOATWEET_API_MODEL_USER_H_

#include <string>

namespace CocoaTweet::API::Model {

/// @brief data class for tweet object
class User final {
public:
  /// @brief constructor
  User() = default;

  /// @brief copy constructor
  User(const User&) = default;

  /// @brief constructor for create object from json response
  /// @param[in] const std::string& _json : received content from twitter endpoint
  User(const std::string& _json) : User(User::parse(_json)) {}

  /// @brief response parser for user object
  /// @param[in] const std::string& _json : received content from twitter endpoint
  /// @param[out] CocoaTweet::API::Model::User
  static User parse(const std::string& _json);

  void id(const std::string& _id);
  void name(const std::string& _name);
  void screenName(const std::string& _screen);
  void location(const std::string& _location);
  void url(const std::string& _url);
  void description(const std::string& _description);
  void protectedUser(const bool _protected);
  void follower(const long _follower);
  void follow(const long _follow);
  void listed(const long _listed);
  void favorite(const long _favorite);
  void tweet(const long _tweet);
  void createdAt(const std::string& _created);
  void bannerUrl(const std::string& _banner);
  void iconUrl(const std::string& _icon);

  const std::string& id() const;
  const std::string& name() const;
  const std::string& screenName() const;
  const std::string& location() const;
  const std::string& url() const;
  const std::string& description() const;
  bool protectedUser() const;
  long follower() const;
  long follow() const;
  long listed() const;
  long favorite() const;
  long tweet() const;
  const std::string& created() const;
  const std::string& banner() const;
  const std::string& icon() const;

private:
  std::string id_;
  std::string name_;
  std::string screenName_;
  std::string location_;
  std::string url_;
  std::string description_;
  bool protectedUser_;
  long follower_;
  long follow_;
  long listed_;
  long favorite_;
  long tweet_;
  std::string createdAt_;
  std::string bannerUrl_;
  std::string iconUrl_;
};
} // namespace CocoaTweet::API::Model

#endif
