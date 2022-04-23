#include "bearerToken.h"

namespace CocoaTweet::API::Model {

BearerToken::BearerToken() : token_("") {}
BearerToken::BearerToken(const std::string _token) : token_(_token) {}
const std::string& BearerToken::token() const {
  return token_;
}
void BearerToken::token(const std::string& _token) {
  token_ = _token;
}
} // namespace CocoaTweet::API::Model