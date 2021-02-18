#include "cocoatweet/api/status/destroy.h"

namespace CocoaTweet::API::Statuses {
Destroy::Destroy() {}
void Destroy::id(const std::string _id) {
  url_ = "https://api.twitter.com/1.1/statuses/destroy/" + _id + ".json";
}

} // namespace CocoaTweet::API::Statuses
