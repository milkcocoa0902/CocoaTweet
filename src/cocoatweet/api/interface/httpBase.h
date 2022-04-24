#ifndef COCOATWEET_API_INTERFACE_HTTPBASE_H_
#define COCOATWEET_API_INTERFACE_HTTPBASE_H_

#include <functional>
#include <memory>
#include "cocoatweet/authentication/authenticator.h"

namespace CocoaTweet::API::Interface {
class HttpBase {
public:
protected:
  std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> oauth_;
  std::map<std::string, std::string> bodyParam_;
  std::string url_;
  std::string contentType_;
  virtual void process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth,
                       std::function<void(const std::string&)> _callback) = 0;
  static size_t curlCallback_(char* _ptr, size_t _size, size_t _nmemb, std::string* _stream) {
    int realsize = _size * _nmemb;
    _stream->append(_ptr, realsize);
    return realsize;
  }
};
} // namespace CocoaTweet::API::Interface

#endif
