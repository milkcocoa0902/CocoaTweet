#include <iostream>

#include "cocoatweet/api/status/status.h"
#include "cocoatweet/api/status/update.h"

namespace CocoaTweet::API::Statuses{
		Status::Status(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth){
			oauth_ = _oauth;
		}

		void Status::Update(const std::string& _status)const{
				CocoaTweet::API::Statuses::Update update;
				update.status(_status);
				update.process(oauth_, [](std::string _rcv){std::cout << _rcv << std::endl;});
		}
}
