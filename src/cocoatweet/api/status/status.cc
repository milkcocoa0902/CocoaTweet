#include "cocoatweet/api/status/status.h"
#include "cocoatweet/api/status/update.h"
#include "cocoatweet/api/status/destroy.h"
#include "cocoatweet/api/status/retweet.h"
#include "cocoatweet/api/status/unretweet.h"
#include "cocoatweet/api/status/userTimeline.h"

namespace CocoaTweet::API::Statuses {
Status::Status(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  oauth_ = _oauth;
}

CocoaTweet::API::Model::Tweet Status::update(const std::string& _status) const {
  CocoaTweet::API::Statuses::Update update;
  update.status(_status);
  return update.process(oauth_);
}

CocoaTweet::API::Model::Tweet Status::update(const std::string& _status,
                                             const Options _options) const {
  CocoaTweet::API::Statuses::Update update;
  update.status(_status);

  if (_options.replyToStatusId != defaultOpt_.replyToStatusId) {
    update.replyToStatusId(_options.replyToStatusId);
  }

  if (_options.autoPopulateReplyMetaData != defaultOpt_.autoPopulateReplyMetaData) {
    update.autoPopulateReplyMetaData(_options.autoPopulateReplyMetaData);
  }

  if (_options.excludeReplyUserId != defaultOpt_.excludeReplyUserId) {
    update.excludeReplyUserId(_options.excludeReplyUserId);
  }

  if (_options.attachmentUrl != defaultOpt_.attachmentUrl) {
    update.attachmentUrl(_options.attachmentUrl);
  }

  if (_options.coord != defaultOpt_.coord) {
    update.coord(_options.coord);
  }

  if (_options.displayCoord != defaultOpt_.displayCoord) {
    update.displayCoord(_options.displayCoord);
  }

  if (_options.trimUser != defaultOpt_.trimUser) {
    update.trimUser(_options.trimUser);
  }

  if (_options.enableDMCommands != defaultOpt_.enableDMCommands) {
    update.enableDMCommands(_options.enableDMCommands);
  }

  if (_options.failDMCommands != defaultOpt_.failDMCommands) {
    update.failDMCommands(_options.failDMCommands);
  }

  return update.process(oauth_);
}

CocoaTweet::API::Model::Tweet Status::update(const std::string& _status,
                                             std::vector<std::string> _mediaId) const {
  CocoaTweet::API::Statuses::Update update;
  update.status(_status);
  update.mediaId(_mediaId);
  return update.process(oauth_);
}

CocoaTweet::API::Model::Tweet Status::destroy(const std::string& _id) const {
  CocoaTweet::API::Statuses::Destroy destroy;
  destroy.id(_id);
  return destroy.process(oauth_);
}

CocoaTweet::API::Model::Tweet Status::retweet(const std::string& _id) const {
  CocoaTweet::API::Statuses::Retweet retweet;
  retweet.id(_id);
  return retweet.process(oauth_);
}

CocoaTweet::API::Model::Tweet Status::unretweet(const std::string& _id) const {
  CocoaTweet::API::Statuses::Unretweet unretweet;
  unretweet.id(_id);
  return unretweet.process(oauth_);
}

std::vector<CocoaTweet::API::Model::Tweet> Status::userTimeline(
    const std::string& _screenName) const {
  CocoaTweet::API::Statuses::UserTimeline userTimeline;
  userTimeline.screenName(_screenName);
  return userTimeline.process(oauth_);
}
} // namespace CocoaTweet::API::Statuses
