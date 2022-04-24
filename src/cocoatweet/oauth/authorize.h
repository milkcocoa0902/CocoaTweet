#ifndef COCOATWEET_OAUTH_AUTHORIZE_H_
#define COCOATWEET_OAUTH_AUTHORIZE_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include <vector>
#include <utility>

namespace CocoaTweet::Authentication {
class Auth : public groupInterface {
public:
  enum AuthType { OAuth, Bearer };

  Auth();
  Auth(Key _key);
  authorize(const bool app_only);

private:
  Key key_;
}
} // namespace CocoaTweet::Authentication

#endif