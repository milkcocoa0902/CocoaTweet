#ifndef COCOATWEET_EXCEPTION_TWEETNOTFOUNDEXCEPTION_H_
#define COCOATWEET_EXCEPTION_TWEETNOTFOUNDEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class TweetNotFoundException final : Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
