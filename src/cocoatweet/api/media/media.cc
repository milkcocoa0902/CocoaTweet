#include "cocoatweet/api/media/media.h"

namespace CocoaTweet::API::Medias {
Media::Media(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  oauth_ = _oauth;
}

CocoaTweet::API::Model::MediaStore Media::upload(const std::string& _media) const {
  CocoaTweet::API::Medias::Upload upload;
  upload.media(_media);
  return upload.process(oauth_);
}
} // namespace CocoaTweet::API::Medias
