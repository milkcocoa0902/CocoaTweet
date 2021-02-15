#ifndef COCOATWEET_API_GROUPINTERFACE_H_
#define COCOATWEET_API_GROUPINTERFACE_H_

#include <memory>
#include "cocoatweet/oauth/oauth.h"

namespace CocoaTweet::API{
class groupInterface{
protected:
		std::weak_ptr<CocoaTweet::OAuth::OAuth1> oauth_;
};
}

#endif
