#ifndef COCOATWEET_API_MODEL_MEDIASTORE_H_
#define COCOATWEET_API_MODEL_MEDIASTORE_H_

#include <string>

namespace CocoaTweet::API::Model {

/// @brief data class for tweet object
class MediaStore final {
public:
  /// @brief constructor
  MediaStore() = default;

  /// @brief copy constructor
  MediaStore(const MediaStore&) = default;

  /// @brief constructor for create object from json response
  /// @param[in] const unsigned int _responseCode : http status code which received when post
  /// request
  /// @param[in] const std::string& _json : received content from twitter endpoint
  MediaStore(const unsigned int _responseCode, const std::string& _json)
      : MediaStore(MediaStore::parse(_responseCode, _json)) {}

  /// @brief response parser for tweet object
  /// @param[in] const unsigned int _responseCode : http status code which received when post
  /// request
  /// @param[in] const std::string& _json : received content from twitter endpoint
  /// @param[out] CocoaTweet::API::Model::Tweet
  static MediaStore parse(const unsigned int _responseCode, const std::string& _json);

  /// @brief set id of tweet
  /// @param[in] const std::string _id : tweet id to set
  /// @param[out] none
  void id(const std::string _id);

  /// @brief set created time of tweet
  /// @param[in] const std::string _at : tweet created time to set
  /// @param[out] none
  void size(const unsigned int _size);

  /// @brief set tweet text
  /// @param[in] const std::string _text : text of tweet to set
  /// @param[out] none
  void expires(const unsigned int _ex);

  /// @brief set tweet source
  /// @param[in] const std::string _source : source information to set
  /// @param[out] none
  void state(const std::string _state);

  void remain(const unsigned int _remain);

  /// @brief get tweet id
  /// @param[in] none
  /// @param[out] const std::string : tweet id
  const std::string id() const;

  /// @brief get tweet create time
  /// @param[in] none
  /// @param[out] const std::string : time of tweet created time
  const unsigned int size() const;

  /// @brief get tweet text
  /// @param[in] none
  /// @param[out] const std::string : tweet text
  const unsigned int expire() const;

  /// @brief get tweet source information
  /// @param[in] none
  /// @param[out] const std::string : source information
  const std::string state() const;

  const unsigned int remain() const;

private:
  std::string id_;
  unsigned long long size_;
  unsigned long long expires_;
  std::string state_;
  unsigned long long remain_;
};
} // namespace CocoaTweet::API::Model

#endif
