#ifndef COCOATWEET_API_STATUSES_DESTROY_H_
#define COCOATWEET_API_STATUSES_DESTROY_H_

#include <memory>

#include "cocoatweet/api/interface/httpPost.h"
//#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Statuses {
class Destroy : public CocoaTweet::API::Interface::HttpPost {
public:
  Destroy();
  void id(const std::string _id);
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
};
} // namespace CocoaTweet::API::Statuses

#endif
