#ifndef COCOATWEET_API_INTERFACE_GROUPINTERFACE_H_
#define COCOATWEET_API_INTERFACE_GROUPINTERFACE_H_

#include <memory>
#include "cocoatweet/authentication/authenticator.h"

namespace CocoaTweet::API {
class groupInterface {
protected:
  std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> oauth_;
};
} // namespace CocoaTweet::API

#endif
