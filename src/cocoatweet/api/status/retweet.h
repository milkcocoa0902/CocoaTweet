#ifndef COCOATWEET_API_STATUS_RETWEET_H_
#define COCOATWEET_API_STATUS_RETWEET_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Statuses {
class Retweet : public CocoaTweet::API::Interface::HttpPost {
public:
  Retweet();

  void id(const std::string& _id);

  CocoaTweet::API::Model::Tweet process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
};
} // namespace CocoaTweet::API::Statuses

#endif