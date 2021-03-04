#include "cocoatweet/api/status/status.h"
#include "cocoatweet/api/status/update.h"
#include "cocoatweet/api/status/destroy.h"

namespace CocoaTweet::API::Statuses {
Status::Status(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  oauth_ = _oauth;
}

CocoaTweet::API::Model::Tweet Status::Update(const std::string& _status) const {
  CocoaTweet::API::Statuses::Update update;
  update.status(_status);
  return update.process(oauth_);
}

CocoaTweet::API::Model::Tweet Status::Destroy(const std::string& _id) const {
  CocoaTweet::API::Statuses::Destroy destroy;
  destroy.id(_id);
  return destroy.process(oauth_);
}
} // namespace CocoaTweet::API::Statuses
