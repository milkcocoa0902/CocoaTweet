#ifndef COCOATWEET_API_API_H_
#define COCOATWEET_API_API_H_

#include <cocoatweet/api/user/user.h>
#include <cocoatweet/api/status/status.h>
#include <cocoatweet/api/favorite/favorite.h>
#include <cocoatweet/api/media/media.h>
#include <cocoatweet/api/directMessage/directMessage.h>
#include <cocoatweet/authentication/authenticator.h>
#include <cocoatweet/api/oauth1/oauth.h>
#include <cocoatweet/api/oauth2/oauth2.h>

namespace CocoaTweet::API {
/// @brief Twitter API Entry Point
class API {
public:
  /// @brief primary constructor
  /// @param[in] _key Twitter API Key typed CocoaTweet::Authentication::Key
  API(CocoaTweet::Authentication::Key _key);

  Users::User user() const;

  /// @brief Getter for Grouped by Statuses/*
  /// @param[out] Status object typed CocoaTweet::API::Statuses::Status
  Statuses::Status status() const;

  /// @brief Getter for Grouped by Favorites/*
  /// @param[out] Favorite object typed CococaTweet::API::Favorites::Favorite
  Favorites::Favorite favorite() const;

  Medias::Media media() const;

  DirectMessages::DirectMessage directMessage() const;

  OAuth1::OAuth oauth1() const;
  OAuth2::OAuth2 oauth2() const;

  const std::string& generateBearerToken() const;
  void swapKey(const CocoaTweet::Authentication::Key _key);

private:
  Users::User user_;
  Statuses::Status status_;
  Favorites::Favorite favorite_;
  Medias::Media media_;
  DirectMessages::DirectMessage directMessage_;
  OAuth1::OAuth oauth1_;
  OAuth2::OAuth2 oauth2_;
  std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> oauth_;
};
} // namespace CocoaTweet::API

#endif
