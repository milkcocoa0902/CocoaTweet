#ifndef COCOATWEET_EXCEPTION_TWEETDUPLICATEEXCEPTION_H_
#define COCOATWEET_EXCEPTION_TWEETDUPLICATEEXCEPTION_H_

#include <cocoatweet/exception/exception.h>

namespace CocoaTweet::Exception {
class TweetDuplicateException final : Exception {
  using Exception::Exception;
};
} // namespace CocoaTweet::Exception

#endif
