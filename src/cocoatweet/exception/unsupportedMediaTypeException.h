#ifndef COCOATWEET_EXCEPTION_UNSUPPORTEDMEDIATYPEEXCEPTION_H_
#define COCOATWEET_EXCEPTION_UNSUPPORTEDMEDIATYPEEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class UnsupportedMediaTypeException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
