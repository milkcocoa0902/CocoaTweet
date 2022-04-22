#ifndef COCOATWEET_AUTHENTICATION_AUTHENTICATORBASE_H
#define COCOATWEET_AUTHENTICATION_AUTHENTICATORBASE_H

#include <cocoatweet/authentication/key.h>
namespace CocoaTweet::Authentication{
class AuthenticatorBase{
public:
    enum class AuthenticationMethod{
        OAUTH10A,
        OAUTH2,
        PLAIN,
        NONE
    };
  
  virtual const std::string calculateAuthHeader(std::map<std::string, std::string> _bodyParam,
                                        const std::string& _method, const std::string& _url) = 0;
  
  const Key key() const{
      return key_;
  }

protected:
  AuthenticationMethod method_;
  Key key_;
  static size_t curlCallback_(char* _ptr, size_t _size, size_t _nmemb, std::string* _stream) {
    int realsize = _size * _nmemb;
    _stream->append(_ptr, realsize);
    return realsize;
  }
};
}

#endif
