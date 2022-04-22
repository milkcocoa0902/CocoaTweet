#ifndef COCOATWEET_API_INTERFACE_HTTPGET_H_
#define COCOATWEET_API_INTERFACE_HTTPGET_H_

#include <functional>
#include "cocoatweet/authentication/authenticator.h"
#include <cocoatweet/api/interface/httpBase.h>

namespace CocoaTweet::API::Interface {
/// @brief class for Send request with POST method
class HttpGet : public virtual HttpBase {
public:
protected:
  /// @brief Send HTTP/POST using OAuth object
  /// @param[in] std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth : pointer to OAuth object to
  /// authenticate
  /// @param[in] std::function<void(const unsigned int, const std::string&)> _callback :
  /// callback method for processing to response
  void process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth,
               std::function<void(const std::string&)> _callback);
};
} // namespace CocoaTweet::API::Interface

#endif
