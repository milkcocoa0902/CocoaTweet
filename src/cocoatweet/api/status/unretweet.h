#ifndef COCOATWEET_API_STATUS_UNRETWEET_H_
#define COCOATWEET_API_STATUS_UNRETWEET_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Statuses {
class Unretweet : public CocoaTweet::API::Interface::HttpPost {
public:
  Unretweet();

  void id(const std::string& _id);

  CocoaTweet::API::Model::Tweet process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);
};
} // namespace CocoaTweet::API::Statuses

#endif
