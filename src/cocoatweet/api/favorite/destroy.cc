#include <cocoatweet/api/favorite/destroy.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Favorites {
Destroy::Destroy() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/favorites/destroy.json";
}

void Destroy::id(const std::string& _id) {
  bodyParam_.insert_or_assign("id", _id);
}

CocoaTweet::API::Model::Tweet Destroy::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  CocoaTweet::API::Model::Tweet tweet;
  HttpPost::process(_oauth, [&tweet](const std::string& _rcv) {
    tweet = CocoaTweet::API::Model::Tweet(_rcv);
  });

  return tweet;
}
} // namespace CocoaTweet::API::Favorites
