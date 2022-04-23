#ifndef COCOATWEET_EXCEPTION_MISSINGREQUIREDPARAMEXCEPTION_H_
#define COCOATWEET_EXCEPTION_MISSINGREQUIREDPARAMEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class MissingRequiredParamException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
