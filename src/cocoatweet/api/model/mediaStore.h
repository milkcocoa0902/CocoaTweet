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

  /// @brief response parser for MediaStore object
  /// @param[in] const unsigned int _responseCode : http status code which received when post
  /// request
  /// @param[in] const std::string& _json : received content from twitter endpoint
  /// @param[out] CocoaTweet::API::Model::MediaStore
  static MediaStore parse(const unsigned int _responseCode, const std::string& _json);

  /// @brief set id of tweet
  /// @param[in] const std::string _id : media id to set
  /// @param[out] none
  void id(const std::string _id);

  /// @brief set media size in byte
  /// @param[in] const unsigned int _size : media size in byte
  /// @param[out] none
  void size(const unsigned int _size);

  /// @brief set remaining time to expire the media
  /// @param[in] const unsigned int : remaining time to expire the media ib sec
  /// @param[out] none
  void expires(const unsigned int _ex);

  /// @brief set media processing status
  /// @param[in] const std::string _state : media processed status
  /// @param[out] none
  void state(const std::string _state);

  /// @brief set how second need for upload complete
  /// @param[in] needed time to upload complete on server in second
  /// @param[out] none
  void remain(const unsigned int _remain);

  /// @brief get media id
  /// @param[in] none
  /// @param[out] const std::string : media id
  const std::string id() const;

  /// @brief get media size
  /// @param[in] none
  /// @param[out] const unsigned int : media size in byte
  const unsigned int size() const;

  /// @brief get remaining time to expire the media
  /// @param[in] none
  /// @param[out] const unsigned int : remaining time to expire the media ib sec
  const unsigned int expire() const;

  /// @brief get media processing status
  /// @param[in] none
  /// @param[out] const std::string _state : media processed status
  const std::string state() const;

  /// @brief set how second need for upload complete
  /// @param[in] none
  /// @param[out]  needed time to upload complete on server in second
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
