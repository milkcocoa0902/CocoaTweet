#ifndef COCOATWEET_API_STATUSED_H_
#define COCOATWEET_API_STATUSED_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Statuses {
class Status : public groupInterface {
public:
  Status() = default;
  Status(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
  void Update(const std::string& _status) const;

private:
};
} // namespace CocoaTweet::API::Statuses

#endif
