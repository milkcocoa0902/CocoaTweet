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
	void createdAt(const std::string _at);
	void text(const std::string _text);
	void source(const std::string _source);
  const std::string id() const;
	const std::string createdAt() const;
	const std::string text() const;
	const std::string source() const;

private:
  std::string id_;
	std::string createdAt_;
	std::string text_;
	std::string source_;


};
} // namespace CocoaTweet::API::Model

#endif
