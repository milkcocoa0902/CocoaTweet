#ifndef COCOATWEET_API_USER_SHOW_H_
#define COCOATWEET_API_USER_SHOW_H_

#include <cocoatweet/api/interface/httpGet.h>
#include <cocoatweet/api/model/user.h>
#include <vector>
#include <utility>
#include <memory>

namespace CocoaTweet::API::Users {
/// @brief class for using users/show endpoint
class Show : public CocoaTweet::API::Interface::HttpGet {
public:
  /// @brief primary constructor
  Show();

  /// @brief set screen name to get user information
  /// @param[in] const std::string& _id : screen name for getting information
  void id(const std::string& _id);

  /// @brief set screen name to get user information
  /// @param[in] const std::string& _screenName : screen name for getting information
  void screenName(const std::string& _screenName);

  /// @brief process request for endpoint
  /// @param[in] std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth : pointer to oauth object
  /// @param[out] CocoaTweet::API::Model::User : request result
  CocoaTweet::API::Model::User process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
