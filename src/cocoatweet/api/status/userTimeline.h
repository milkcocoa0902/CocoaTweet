#ifndef COCOATWEET_API_STATUS_USERTIMELINE_H_
#define COCOATWEET_API_STATUS_USERTIMELINE_H_

#include <cocoatweet/api/interface/httpGet.h>
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>
#include <memory>

namespace CocoaTweet::API::Statuses {
/// @brief class for using statuses/update endpoint
class UserTimeline : public CocoaTweet::API::Interface::HttpGet {
public:
  /// @brief primary constructor
  UserTimeline();

  void screenName(const std::string& _screenName);

  /// @brief process request for endpoint
  /// @param[in] std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth : pointer to oauth object
  /// @param[out] CocoaTweet::API::Model::Tweet : request result
  std::vector<CocoaTweet::API::Model::Tweet> process(
      std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
