#include "cocoatweet/api/status/update.h"

namespace CocoaTweet::API::Statuses {
Update::Update() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/statuses/update.json";
}

void Update::status(const std::string _status) {
  status_ = _status;
  bodyParam_.insert_or_assign("status", status_);
}

CocoaTweet::API::Model::Tweet Update::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  CocoaTweet::API::Model::Tweet tweet;
  HttpPost::process(_oauth,
                    [&tweet](const unsigned int _responseCode, const std::string& _rsv) {
                      tweet = CocoaTweet::API::Model::Tweet::parse(_responseCode, _rsv);
                    });
  return tweet;
}

} // namespace CocoaTweet::API::Statuses
