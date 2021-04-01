#ifndef COCOATWEET_API_API_H_
#define COCOATWEET_API_API_H_

#include <cocoatweet/api/status/status.h>
#include <cocoatweet/api/favorite/favorite.h>
#include <cocoatweet/api/media/media.h>
#include <cocoatweet/api/directMessage/directMessage.h>
#include <cocoatweet/oauth/oauth.h>

namespace CocoaTweet::API {
/// @brief Twitter API Entry Point
class API {
public:
  /// @brief primary constructor
  /// @param[in] _key Twitter API Key typed CocoaTweet::OAuth::Key
  API(CocoaTweet::OAuth::Key _key);

  /// @brief Getter for Grouped by Statuses/*
  /// @param[out] Status object typed CocoaTweet::API::Statuses::Status
  Statuses::Status status() const;

  /// @brief Getter for Grouped by Favorites/*
  /// @param[out] Favorite object typed CococaTweet::API::Favorites::Favorite
  Favorites::Favorite favorite() const;

  Medias::Media media() const;

  DirectMessages::DirectMessage directMessage() const;

private:
  Statuses::Status status_;
  Favorites::Favorite favorite_;
  Medias::Media media_;
  DirectMessages::DirectMessage directMessage_;
  std::shared_ptr<CocoaTweet::OAuth::OAuth1> oauth_;
};
} // namespace CocoaTweet::API

#endif
