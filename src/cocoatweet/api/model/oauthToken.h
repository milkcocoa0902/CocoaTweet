#ifndef COCOATWEET_API_MODEL_OAUTHTOKEN_H_
#define COCOATWEET_API_MODEL_OAUTHTOKEN_H_
#include <string>

namespace CocoaTweet::API::Model {
class OAuthToken {
  std::string oauthToken_;
  std::string oauthTokenSecret_;

public:
  OAuthToken();
  OAuthToken(const std::string _oauthToken, const std::string& _oauthTokenSecret);
  const std::string& oauthToken() const;
  const std::string& oauthTokenSecret() const;
  void oauthToken(const std::string& _oauthToken);
  void oauthTokenSecret(const std::string& _oauthTokenSecret);
};
} // namespace CocoaTweet::API::Model

#endif