#ifndef COCOATWEET_API_MODEL_TWEET_H_
#define COCOATWEET_API_MODEL_TWEET_H_

#include <string>

namespace CocoaTweet::API::Model {

/// @brief data class for tweet object
class Tweet final {
public:
  /// @brief constructor
  Tweet() = default;

  /// @brief copy constructor
  Tweet(const Tweet&) = default;

  /// @brief constructor for create object from json response
  /// @param[in] const unsigned int _responseCode : http status code which received when post
  /// request
  /// @param[in] const std::string& _json : received content from twitter endpoint
  Tweet(const unsigned int _responseCode, const std::string& _json)
      : Tweet(Tweet::parse(_responseCode, _json)) {}

  /// @brief response parser for tweet object
  /// @param[in] const unsigned int _responseCode : http status code which received when post
  /// request
  /// @param[in] const std::string& _json : received content from twitter endpoint
  /// @param[out] CocoaTweet::API::Model::Tweet
  static Tweet parse(const unsigned int _responseCode, const std::string& _json);

  /// @brief set id of tweet
  /// @param[in] const std::string _id : tweet id to set
  /// @param[out] none
  void id(const std::string _id);

  /// @brief set created time of tweet
  /// @param[in] const std::string _at : tweet created time to set
  /// @param[out] none
  void createdAt(const std::string _at);

  /// @brief set tweet text
  /// @param[in] const std::string _text : text of tweet to set
  /// @param[out] none
  void text(const std::string _text);

  /// @brief set tweet source
  /// @param[in] const std::string _source : source information to set
  /// @param[out] none
  void source(const std::string _source);

  /// @brief get tweet id
  /// @param[in] none
  /// @param[out] const std::string : tweet id
  const std::string id() const;

  /// @brief get tweet create time
  /// @param[in] none
  /// @param[out] const std::string : time of tweet created time
  const std::string createdAt() const;

  /// @brief get tweet text
  /// @param[in] none
  /// @param[out] const std::string : tweet text
  const std::string text() const;

  /// @brief get tweet source information
  /// @param[in] none
  /// @param[out] const std::string : source information
  const std::string source() const;

private:
  std::string id_;
  std::string createdAt_;
  std::string text_;
  std::string source_;
};
} // namespace CocoaTweet::API::Model

#endif
