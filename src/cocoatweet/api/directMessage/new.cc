#include <cocoatweet/api/directMessage/new.h>
#include <cocoatweet/util/util.h>
#include <string>

namespace CocoaTweet::API::DirectMessages{
    New::New(){
        url_ = "https://api.twitter.com/1.1/direct_messages/events/new.json";
        contentType_ = "application/json";

        nlohmann::json tmp;
        tmp["type"] = "message_create";
        tmp["message_create"] = nlohmann::json::object();
        tmp["message_create"]["target"] = nlohmann::json::object();
        tmp["message_create"]["message_data"] = nlohmann::json::object();
        json_["event"] = tmp;
    }


  void New::recipient(const std::string& _id){
      json_["event"]["message_create"]["target"]["recipient_id"] = std::stol(_id);
  }

  void New::message(const std::string& _message){
      json_["event"]["message_create"]["message_data"]["text"] = _message;
  }

  void New::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth){
      bodyParam_.insert_or_assign("data", json_.dump());
      HttpPost::process(_oauth, [](const std::string& _rcv){});
  }
}