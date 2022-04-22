#include <cocoatweet/api/user/user.h>
#include <cocoatweet/api/user/show.h>

namespace CocoaTweet::API::Users{
    User::User(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  oauth_ = _oauth;
}

    CocoaTweet::API::Model::User User::show(const std::string& _screenName)const{
        CocoaTweet::API::Users::Show show;
        show.screenName(_screenName);
        return show.process(oauth_);
    }
}