#include <cocoatweet/api/oauth1/accessToken.h>
#include <cocoatweet/util/util.h>
#include <iostream>

namespace CocoaTweet::API::OAuth1{
    AccessToken::AccessToken(){
        contentType_ = "application/x-www-form-urlencoded";
        url_         = "https://api.twitter.com/oauth/access_token";
    }

    void AccessToken::oauthVerifier(const std::string& _verifier){
        bodyParam_.insert_or_assign("oauth_verifier", _verifier);
    }

    void AccessToken::oauthToken(const CocoaTweet::API::Model::OAuthToken _token){
        oauthToken_ = _token;
    }

    const CocoaTweet::API::Model::OAuthToken AccessToken::process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth){
        CocoaTweet::API::Model::OAuthToken oauthToken;
        HttpPost::process(_oauth, [&oauthToken](const std::string& _rcv){
            auto mp = CocoaTweet::Util::parse(_rcv, '&', '=');
            if(mp.count("oauth_token")){
                oauthToken.oauthToken(mp.at("oauth_token"));
            }
            if(mp.count("oauth_token_secret")){
                oauthToken.oauthTokenSecret(mp.at("oauth_token_secret"));
            }
            std::cout << _rcv << std::endl;
        });
        return oauthToken;
    }
}