#ifndef COCOATWEET_API_MODEL_TWEET_H_
#define COCOATWEET_API_MODEL_TWEET_H_

#include <string>

namespace CocoaTweet::API::Model {
class Tweet final {
public:
  Tweet()             = default;
  Tweet(const Tweet&) = default;
  Tweet(const unsigned int _responseCode, const std::string& _json)
      : Tweet(Tweet::parse(_responseCode, _json)) {}
  static Tweet parse(const unsigned int _responseCode, const std::string& _json);
  void id(const std::string _id);
  const std::string id() const;

private:
  std::string id_;
};
} // namespace CocoaTweet::API::Model

#endif
