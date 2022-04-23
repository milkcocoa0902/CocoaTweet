#ifndef COCOATWEET_EXCEPTION_CREDETIALNOTALLOWEDEXCEPTION_H_
#define COCOATWEET_EXCEPTION_CREDETIALNOTALLOWEDEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class CredentialNotAllowedException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
