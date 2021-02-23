#ifndef COCOATWEET_EXCEPTION_RATELIMITEXCEPTION_H_
#define COCOATWEET_EXCEPTION_RATELIMITEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class RateLimitException final : Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
