#ifndef COCOATWEET_EXCEPTION_CREDENTIALNOTVERIFIEDEXCEPTION_H_
#define COCOATWEET_EXCEPTION_CREDENTIALNOTVERIFIEDEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class CredentialNotVerifiedException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
