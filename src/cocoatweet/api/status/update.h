#ifndef COCOATWEET_API_STATUSES_UPDATE_H_
#define COCOATWEET_API_STATUSES_UPDATE_H_

#include <memory>
#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Statuses {
class Update : public CocoaTweet::API::Interface::HttpPost {
public:
  Update();
  void status(const std::string _status);
  CocoaTweet::API::Model::Tweet process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
