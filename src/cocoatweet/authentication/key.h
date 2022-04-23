#ifndef COCOATWEET_AUTHENTICATION_KEY_H_
#define COCOATWEET_AUTHENTICATION_KEY_H_

#include <string>
#include <map>

namespace CocoaTweet::Authentication {
class Key {
public:
  enum AUTH_TYPE { OAUTH10A, OAUTH2 };

private:
  std::string consumerKey_;
  std::string consumerSecret_;
  std::string accessToken_;
  std::string accessTokenSecret_;
  std::string bearerToken_;
  AUTH_TYPE authType_;

public:
  Key() : consumerKey_(""), consumerSecret_(""), accessToken_(""), accessTokenSecret_("") {}
  Key(const std::string& _consumerKey, const std::string& _consumerSecret,
      const std::string& _accessToken, const std::string& _accessTokenSecret,
      const AUTH_TYPE _authType = AUTH_TYPE::OAUTH10A)
      : consumerKey_(_consumerKey),
        consumerSecret_(_consumerSecret),
        accessToken_(_accessToken),
        accessTokenSecret_(_accessTokenSecret),
        authType_(_authType) {}
  Key(const std::string& _consumerKey, const std::string& _consumerSecret,
      const AUTH_TYPE _authType = AUTH_TYPE::OAUTH2)
      : consumerKey_(_consumerKey), consumerSecret_(_consumerSecret), authType_(_authType) {}

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

  const AUTH_TYPE authType() const {
    return authType_;
  }

  void authType(AUTH_TYPE _authType) {
    authType_ = _authType;
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
} // namespace CocoaTweet::Authentication

#endif
