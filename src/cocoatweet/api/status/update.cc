#include "cocoatweet/api/status/update.h"
#include <cocoatweet/util/util.h>

namespace CocoaTweet::API::Statuses {
Update::Update() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/update.json";
}

void Update::status(const std::string _status) {
  status_ = _status;
  bodyParam_.insert_or_assign("status", status_);
}

void Update::mediaId(const std::vector<std::string> _media) {
  bodyParam_.insert_or_assign("media_ids", CocoaTweet::Util::join(_media, ","));
}

void Update::replyToStatusId(const std::string _reply) {
  bodyParam_.insert_or_assign("in_reply_to_status_id", _reply);
}

void Update::autoPopulateReplyMetaData(bool _meta) {
  bodyParam_.insert_or_assign("auto_populate_reply_metadata", std::to_string(_meta));
}

void Update::excludeReplyUserId(const std::vector<std::string> _ex) {
  bodyParam_.insert_or_assign("exclude_reply_user_ids", CocoaTweet::Util::join(_ex, ","));
}

void Update::attachmentUrl(const std::string _url) {
  bodyParam_.insert_or_assign("attachment_url", _url);
}

void Update::coord(std::pair<std::string, std::string> _coord) {
  bodyParam_.insert_or_assign("lat", _coord.first);
  bodyParam_.insert_or_assign("long", _coord.second);
}

void Update::displayCoord(bool _disp) {
  bodyParam_.insert_or_assign("display_coordinates", std::to_string(_disp));
}

void Update::trimUser(bool _trim) {
  bodyParam_.insert_or_assign("trim_user", std::to_string(_trim));
}

void Update::enableDMCommands(bool _enable) {
  bodyParam_.insert_or_assign("enable_dmcommands", std::to_string(_enable));
}

void Update::failDMCommands(bool _fail) {
  bodyParam_.insert_or_assign("fail_dmcommands", std::to_string(_fail));
}

CocoaTweet::API::Model::Tweet Update::process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  CocoaTweet::API::Model::Tweet tweet;
  HttpPost::process(_oauth, [&tweet](const std::string& _rcv) {
    tweet = CocoaTweet::API::Model::Tweet::parse(_rcv);
  });
  return tweet;
}

} // namespace CocoaTweet::API::Statuses
