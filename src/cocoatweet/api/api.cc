#include <cocoatweet/api/api.h>

namespace CocoaTweet::API{
    API::API(CocoaTweet::OAuth::Key _key){
        oauth_ = std::make_shared<CocoaTweet::OAuth::OAuth1>(_key);
        status_ = Statuses::Status(oauth_);
    }

    Statuses::Status API::status() const{
        return status_;
    }
}