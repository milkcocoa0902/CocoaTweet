#ifndef COCOATWEET_EXCEPTION_INVALIDATETOKENEXCEPTION_H_
#define COCOATWEET_EXCEPTION_INVALIDATETOKENEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class InvalidateTokenException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
