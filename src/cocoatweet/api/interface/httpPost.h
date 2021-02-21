#ifndef COCOATWEET_API_INTERFACE_POSTINTERFACE_H_
#define COCOATWEET_API_INTERFACE_POSTINTERFACE_H_

#include <functional>
#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API::Interface {
class HttpPost {
public:

protected:
  std::weak_ptr<CocoaTweet::OAuth::OAuth1> oauth_;
  std::map<std::string, std::string> bodyParam_;
  std::string url_;
  std::string contentType_;
  void process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth,
               std::function<void(std::string)> _callback);
  static size_t curlCallback_(char* _ptr, size_t _size, size_t _nmemb, std::string* _stream);
};
} // namespace CocoaTweet::API::Interface

#endif
