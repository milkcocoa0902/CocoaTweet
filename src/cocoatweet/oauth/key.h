#ifndef COCOATWEET_OAUTH_KEY_H_
#define COCOATWEET_OAUTH_KEY_H_

#include <string>
#include <map>

namespace CocoaTweet::OAuth {
class Key {
  std::string consumerKey_;
  std::string consumerSecret_;
  std::string accessToken_;
  std::string accessTokenSecret_;
  std::string bearerToken_;

public:
  Key() : consumerKey_(""), consumerSecret_(""), accessToken_(""), accessTokenSecret_("") {}
  Key(const std::string& _consumerKey, const std::string& _consumerSecret,
      const std::string& _accessToken, const std::string& _accessTokenSecret)
      : consumerKey_(_consumerKey),
        consumerSecret_(_consumerSecret),
        accessToken_(_accessToken),
        accessTokenSecret_(_accessTokenSecret) {}
  Key(const std::string& _consumerKey, const std::string& _consumerSecret)
      : consumerKey_(_consumerKey), consumerSecret_(_consumerSecret) {}

  void consumerKey(const std::string& _consumerKey) {
    consumerKey_ = _consumerKey;
  }

  void consumerSecret(const std::string& _consumerSecret) {
    consumerSecret_ = _consumerSecret;
  }

  void accessToken(const std::string& _accessToken) {
    accessToken_ = _accessToken;
  }

  void accessTokenSecret(const std::string& _accessTokenSecret) {
    accessTokenSecret_ = _accessTokenSecret;
  }

  void bearerToken(const std::string& _bearer) {
    bearerToken_ = _bearer;
  }
  const std::string& consumerKey() const {
    return consumerKey_;
  }
  const std::string& consumerSecret() const {
    return consumerSecret_;
  }
  const std::string& accessToken() const {
    return accessToken_;
  }
  const std::string& accessTokenSecret() const {
    return accessTokenSecret_;
  }

  const std::string& bearerToken() const {
    return bearerToken_;
  }

  std::map<std::string, std::string> noSecret() const {
    return std::map<std::string, std::string>{{"oauth_consumer_key", consumerKey_},
                                              {"oauth_token", accessToken_}};
  }
  const std::map<std::string, std::string> secret() const {
    return std::map<std::string, std::string>{{"oauth_consumer_key", consumerSecret_},
                                              {"oauth_token", accessTokenSecret_}};
  }

  static Key fromJsonFile(const std::string _jsonFile);
};
} // namespace CocoaTweet::OAuth

#endif
