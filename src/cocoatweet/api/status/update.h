#ifndef COCOATWEET_API_STATUSES_UPDATE_H_
#define COCOATWEET_API_STATUSES_UPDATE_H_

#include <memory>

#include "cocoatweet/api/interface/interface.h"
//#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Statuses {
class Update : public Interface {
public:
  Update();
  void status(const std::string _status);
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth,
               std::function<void(std::string)> _callback);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
