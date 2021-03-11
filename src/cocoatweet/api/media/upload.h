#ifndef COCOATWEET_API_MEDIA_UPLOAD_H_
#define COCOATWEET_API_MEDIA_UPLOAD_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/mediaStore.h>
#include <string>
#include <filesystem>

namespace CocoaTweet::API::Medias {
class Upload : public CocoaTweet::API::Interface::HttpPost {
private:
  std::string media_;
  static const std::map<std::string, std::string> mimeType;
  ;

public:
  Upload();
  void media(const std::string& _media);
  void mediaId(const std::string& _mediaId);
  CocoaTweet::API::Model::MediaStore process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
};
} // namespace CocoaTweet::API::Medias

#endif
