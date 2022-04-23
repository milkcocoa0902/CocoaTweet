#include <cocoatweet/api/oauth2/token.h>
#include "nlohmann/json.hpp"


namespace CocoaTweet::API::OAuth2{
    Token::Token(){
        contentType_ = "application/x-www-form-urlencoded";
        url_ = "https://api.twitter.com/oauth2/token";

        bodyParam_.insert_or_assign("grant_type", "client_credentials");
    }



const std::string Token::process(std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  auto basic = std::make_shared<CocoaTweet::Authentication::Basic>(_oauth.lock()->key());
  std::string bearer = "";
  HttpPost::process(basic, [&bearer](const std::string& _rcv) {
    auto j = nlohmann::json::parse(_rcv);
    bearer = j["access_token"];
  });
  return bearer;
}

}