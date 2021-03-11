#ifndef COCOATWEET_API_STATUS_DESTROY_H_
#define COCOATWEET_API_STATUS_DESTROY_H_

#include <memory>
#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Statuses {
/// @brief class for using status/destroy:id endpoint
class Destroy : public CocoaTweet::API::Interface::HttpPost {
public:
  /// @brief primary constructor
  Destroy();

  /// @brief set tweet id to destroy
  /// @param[in]  std::string _id : tweet id which should be destroy
  /// @param[out] none
  void id(const std::string _id);

  /// @brief process request for endpoint
  /// @param[in] std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth : pointer to oauth object
  /// @param[out] CocoaTweet::API::Model::Tweet : request result
  CocoaTweet::API::Model::Tweet process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
};
} // namespace CocoaTweet::API::Statuses

#endif
