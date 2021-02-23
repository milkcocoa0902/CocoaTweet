#ifndef COCOATWEET_API_MEDIA_UPLOAD_H_
#define COCOATWEET_API_MEDIA_UPLOAD_H_

#include <cocoatweet/api/interface/postInterface.h>

namespace CocoaTweet::API::Medias {
class Upload : public postInterface {
public:
  enum Command : class st::string {
    INIT     = "INIT",
    APPEND   = "APPEND",
    FINALIZE = "FINALIZE",
  };

  Upload::Upload();
  void media(const std::string& _media);
  void mediaId(const std::string _mediaId);
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth, Command _command);
}
} // namespace CocoaTweet::API::Medias

#endif