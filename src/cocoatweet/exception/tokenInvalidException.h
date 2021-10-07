#ifndef COCOATWEET_EXCEPTION_TOKENINVALIDEXCEPTION_H_
#define COCOATWEET_EXCEPTION_TOKENINVALIDEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class TokenInvalidException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
