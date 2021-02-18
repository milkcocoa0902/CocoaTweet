#ifndef COCOATWEET_API_STATUSES_DESTROY_H_
#define COCOATWEET_API_STATUSES_DESTROY_H_

#include <memory>

#include "cocoatweet/api/interface/postInterface.h"
//#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Statuses {
class Destroy : public CocoaTweet::API::Interface::postInterface {
public:
  Destroy();
  void id(const std::string _id);
};
} // namespace CocoaTweet::API::Statuses

#endif
