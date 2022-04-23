#ifndef COCOATWEET_API_STATUS_USERTIMELINE_H_
#define COCOATWEET_API_STATUS_USERTIMELINE_H_

#include <cocoatweet/api/interface/httpGet.h>
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>
#include <memory>

namespace CocoaTweet::API::Statuses {
/// @brief class for using statuses/user_timeline endpoint
class UserTimeline : public CocoaTweet::API::Interface::HttpGet {
public:
  /// @brief primary constructor
  UserTimeline();

  /// @brief set screen name to get timeline
  /// @param[in] const std::string& _screenName : screen name for getting tweet
  void screenName(const std::string& _screenName);

  /// @brief process request for endpoint
  /// @param[in] std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth : pointer
  /// to oauth object
  /// @param[out] std::vector<CocoaTweet::API::Model::Tweet> : request result
  std::vector<CocoaTweet::API::Model::Tweet> process(
      std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
