#ifndef COCOATWEET_OAUTH_KEY_H_
#define COCOATWEET_OAUTH_KEY_H_

#include <map>

namespace CocoaTweet::OAuth {
class Key {
  const std::string consumerKey_;
  const std::string consumerSecret_;
  const std::string accessToken_;
  const std::string accessTokenSecret_;

public:
  Key() = default;
  Key(const std::string& _consumerKey, const std::string& _consumerSecret,
      const std::string& _accessToken, const std::string& _accessTokenSecret)
      : consumerKey_(_consumerKey),
        consumerSecret_(_consumerSecret),
        accessToken_(_accessToken),
        accessTokenSecret_(_accessTokenSecret) {}
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
