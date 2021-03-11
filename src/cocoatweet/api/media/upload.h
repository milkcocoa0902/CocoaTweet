#ifndef COCOATWEET_API_MEDIA_UPLOAD_H_
#define COCOATWEET_API_MEDIA_UPLOAD_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/mediaStore.h>
#include <string>
#include <filesystem>

namespace CocoaTweet::API::Medias {
/// @brief entry point for using media/upload endpoint
class Upload : public CocoaTweet::API::Interface::HttpPost {
private:
  std::string media_;
  static const std::map<std::string, std::string> mimeType;

public:
  /// @brief default constructor
  Upload();

  /// @brief set media file with absolute path
  /// @param[in] const std::string& _media : absolute path to media should be uploaded
  /// @param[out] none
  void media(const std::string& _media);

  /// @brief set media id(no affect to process. will be obsoleted)
  void mediaId(const std::string& _mediaId);

  /// @brief upload media
  /// @param[in] std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth : pointer to OAuth object for
  /// authenticate
  /// @param[out] CocoaTweet::API::Model::MediaStore : media upload result. use id() for post
  /// tweet.
  CocoaTweet::API::Model::MediaStore process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
};
} // namespace CocoaTweet::API::Medias

#endif
