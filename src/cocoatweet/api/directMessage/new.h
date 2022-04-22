#ifndef COCOATWEET_API_DIRECTMESSAGE_NEW_H_
#define COCOATWEET_API_DIRECTMESSAGE_NEW_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>
#include <memory>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::DirectMessages {
/// @brief class for using statuses/update endpoint
class New : public CocoaTweet::API::Interface::HttpPost {
public:
  New();
  void recipient(const std::string& _id);
  void message(const std::string& _message);

  /// @brief process request for endpoint
  /// @param[in] std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth : pointer to oauth object
  /// @param[out] CocoaTweet::API::Model::Tweet : request result
  void process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

private:
  std::string status_;
  nlohmann::json json_;
};
} // namespace CocoaTweet::API::DirectMessages

#endif
