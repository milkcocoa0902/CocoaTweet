#ifndef COCOATWEET_EXCEPTION_INVAILDPARAMETEREXCEPTION_H_
#define COCOATWEET_EXCEPTION_INVAILDPARAMETEREXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class InvalidParameterException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
