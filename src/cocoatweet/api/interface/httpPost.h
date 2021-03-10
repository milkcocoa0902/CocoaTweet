#ifndef COCOATWEET_API_INTERFACE_HTTPPOST_H_
#define COCOATWEET_API_INTERFACE_HTTPPOST_H_

#include <functional>
#include "cocoatweet/oauth/oauth.h"
#include <cocoatweet/api/interface/httpBase.h>

namespace CocoaTweet::API::Interface {
class HttpPost : public HttpBase {
public:
protected:
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth,
               std::function<void(const unsigned int, const std::string&)> _callback);
};
} // namespace CocoaTweet::API::Interface

#endif
