#ifndef COCOATWEET_API_MEDIAS_MEDIA_H_
#define COCOATWEET_API_MEDIAS_MEDIA_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/oauth/oauth.h"
#include <cocoatweet/api/model/mediaStore.h>
#include <cocoatweet/api/media/upload.h>
#include <vector>

namespace CocoaTweet::API::Medias {

/// @brief Entory point for statuses/*
class Media : public groupInterface {
public:
  /// @brief  primary constructor to allow for create NON-INITIALIZED object
  Media() = default;

  /// @brief   constructor which finally should to be called.
  /// @param[in] std::shared_ptr<CocoaTweet::OAuth::OAuth1> : pointer to OAuth object
  Media(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

  CocoaTweet::API::Model::MediaStore Upload(const std::string& _file) const;

private:
};
} // namespace CocoaTweet::API::Medias

#endif
