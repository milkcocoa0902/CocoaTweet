#ifndef COCOATWEET_API_OAUTH1_OAUTH_H_
#define COCOATWEET_API_OAUTH1_OAUTH_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include <cocoatweet/api/oauth1/accessToken.h>
#include <cocoatweet/api/oauth1/requestToken.h>
#include <cocoatweet/api/oauth1/authorize.h>
#include <cocoatweet/api/oauth1/invalidateToken.h>
#include <cocoatweet/api/model/oauthToken.h>
#include <vector>
#include <utility>

namespace CocoaTweet::API::OAuth1 {
/// @brief class for using users/show endpoint
class OAuth : public groupInterface {
public:
  /// @brief primary constructor
  OAuth() = default;

  /// @brief   constructor which finally should to be called.
  /// @param[in] std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> : pointer to
  /// OAuth object
  OAuth(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

  CocoaTweet::API::Model::OAuthToken requestToken(const std::string& _oauthCallback) const;
  const std::string authorize(const CocoaTweet::API::Model::OAuthToken _oauthToken) const;
  const CocoaTweet::API::Model::OAuthToken accessToken(
      const CocoaTweet::API::Model::OAuthToken _oauthToken, const std::string _verifier) const;
  const CocoaTweet::API::Model::OAuthToken invalidateToken() const;
};
} // namespace CocoaTweet::API::OAuth1

#endif
