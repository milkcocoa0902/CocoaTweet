#ifndef COCOATWEET_API_OAUTH1_AUTHORIZE_H
#define COCOATWEET_API_OAUTH1_AUTHORIZE_H

#include <cocoatweet/api/interface/httpPost.h>
namespace CocoaTweet::API::OAuth1{
    class Authorize: public CocoaTweet::API::Interface::HttpPost {
public:
    Authorize();

    void oauthToken(const std::string& _oauthToken);

    void forceLogin(const bool _forceLogin);

    void screenName(const std::string& _screenName);

    const std::string process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> __unused__) ;
    };
}

#endif