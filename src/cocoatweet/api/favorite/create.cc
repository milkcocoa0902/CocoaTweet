#include <cocoatweet/api/favorite/create.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Favorites {
Create::Create() {
  contentType_ = "application/x-www-form-urlencoded";
  url_         = "https://api.twitter.com/1.1/favorites/create.json";
}

void Create::id(const std::string& _id) {
  bodyParam_.insert_or_assign("id", _id);
}

CocoaTweet::API::Model::Tweet Create::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  CocoaTweet::API::Model::Tweet tweet;
  HttpPost::process(_oauth, [&tweet](const std::string& _rcv) {
    tweet = CocoaTweet::API::Model::Tweet(_rcv);
  });

  return tweet;
}
} // namespace CocoaTweet::API::Favorites
