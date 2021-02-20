#ifndef COCOATWEET_API_FAVORITE_CREATE_H_
#define COCOATWEET_API_FAVORITE_CREATE_H_

#include <cocoatweet/api/interface/postInterface.h>

namespace CocoaTweet::API::Favorites {
class Create : public CocoaTweet::API::Interface::postInterface {
public:
  Create();
  void id(const std::string& _id);
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

private:
};
} // namespace CocoaTweet::API::Favorites

#endif
