#include "cocoatweet/api/status/update.h"

namespace CocoaTweet::API::Statuses {
Update::Update() {
  url_ = "https://api.twitter.com/1.1/statuses/update.json";
}
void Update::status(const std::string _status) {
  status_ = _status;
  bodyParam_.insert_or_assign("status", status_);
}

} // namespace CocoaTweet::API::Statuses
