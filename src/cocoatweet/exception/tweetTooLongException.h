#ifndef COCOATWEET_EXCEPTION_TWEETTOOLONGEXCEPTION_H_
#define COCOATWEET_EXCEPTION_TWEETTOOLONGEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class TweetTooLongException final : public Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
