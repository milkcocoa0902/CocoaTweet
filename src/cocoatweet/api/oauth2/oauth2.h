#ifndef COCOATWEET_API_OAUTH2_OAUTH2_H_
#define COCOATWEET_API_OAUTH2_OAUTH2_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include <cocoatweet/api/oauth2/token.h>
#include <cocoatweet/api/model/oauthToken.h>
#include <vector>
#include <utility>

namespace CocoaTweet::API::OAuth2 {
/// @brief class for using users/show endpoint
class OAuth2 : public groupInterface {
public:
  /// @brief primary constructor
  OAuth2() = default;

  /// @brief   constructor which finally should to be called.
  /// @param[in] std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> : pointer to
  /// OAuth object
  OAuth2(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

  const std::string token() const;
};
} // namespace CocoaTweet::API::OAuth2

#endif
