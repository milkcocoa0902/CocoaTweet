#ifndef COCOATWEET_API_FAVORITE_DESTROY_H_
#define COCOATWEET_API_FAVORITE_DESTROY_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>

namespace CocoaTweet::API::Favorites {
class Destroy : public CocoaTweet::API::Interface::HttpPost {
public:
  Destroy();
  void id(const std::string& _id);
  CocoaTweet::API::Model::Tweet process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

private:
};
} // namespace CocoaTweet::API::Favorites

#endif
