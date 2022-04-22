#ifndef COCOATWEET_API_DIRECTMESSAGE_DIRECTMESSAGE_H_
#define COCOATWEET_API_DIRECTMESSAGE_DIRECTMESSAGE_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/authentication/authenticator.h"
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>

namespace CocoaTweet::API::DirectMessages {

/// @brief Entory point for statuses/*
class DirectMessage : public groupInterface {
public:
  DirectMessage() = default;

  /// @brief   constructor which finally should to be called.
  /// @param[in] std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> : pointer to OAuth object
  DirectMessage(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

  void messageCreate(const std::string& _recipient, const std::string& _message);

private:
};
} // namespace CocoaTweet::API::DirectMessages

#endif
