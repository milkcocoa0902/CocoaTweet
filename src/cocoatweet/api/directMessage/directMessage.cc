#include <cocoatweet/api/directMessage/directMessage.h>
#include <cocoatweet/api/directMessage/new.h>

namespace CocoaTweet::API::DirectMessages {
DirectMessage::DirectMessage(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  oauth_ = _oauth;
}

void DirectMessage::messageCreate(const std::string& _recipient, const std::string& _message) {
  CocoaTweet::API::DirectMessages::New dm;
  dm.recipient(_recipient);
  dm.message(_message);
  dm.process(oauth_);
}
} // namespace CocoaTweet::API::DirectMessages