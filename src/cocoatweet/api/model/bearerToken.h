#ifndef COCOATWEET_API_MODEL_BEARERTOKEN_H_
#define COCOATWEET_API_MODEL_BEARERTOKEN_H_
#include <string>

namespace CocoaTweet::API::Model {
class BearerToken {
  std::string token_;

public:
  BearerToken();
  BearerToken(const std::string _token);
  const std::string& token() const;
  void token(const std::string& _token);
};
} // namespace CocoaTweet::API::Model

#endif