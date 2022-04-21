#ifndef COCOATWEET_API_USER_USER_H_
#define COCOATWEET_API_USER_USER_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/oauth/oauth.h"
#include <cocoatweet/api/model/user.h>
#include <vector>
#include <utility>

namespace CocoaTweet::API::Users {
/// @brief class for using users/show endpoint
class User : public groupInterface {
public:
  /// @brief primary constructor
  User() = default;
  
  /// @brief   constructor which finally should to be called.
  /// @param[in] std::shared_ptr<CocoaTweet::OAuth::OAuth1> : pointer to OAuth object
  User(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

  CocoaTweet::API::Model::User show(const std::string& _screenName) const;

};
} // namespace CocoaTweet::API::Statuses

#endif
