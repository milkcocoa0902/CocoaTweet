#ifndef COCOATWEET_EXCEPTION_AUTHENTICATEEXCEPTION_H_
#define COCOATWEET_EXCEPTION_AUTHENTICATEEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class AuthenticateException final : Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
