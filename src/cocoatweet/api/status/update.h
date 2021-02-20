#ifndef COCOATWEET_API_STATUSES_UPDATE_H_
#define COCOATWEET_API_STATUSES_UPDATE_H_

#include <memory>

#include "cocoatweet/api/interface/postInterface.h"
//#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Statuses {
class Update : public CocoaTweet::API::Interface::postInterface {
public:
  Update();
  void status(const std::string _status);
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
