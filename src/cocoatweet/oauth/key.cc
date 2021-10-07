#include "cocoatweet/oauth/key.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <typeinfo>


namespace CocoaTweet::OAuth {
Key Key::fromJsonFile(const std::string _jsonFile) {
  std::ifstream ifs(_jsonFile);
  std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

  auto j = nlohmann::json::parse(str);
  Key key;
  if(j.contains("consumer_key")){
    key.consumerKey(j["consumer_key"].get<std::string>());
  }

  
  if(j.contains("consumer_secret")){
    key.consumerSecret(j["consumer_secret"].get<std::string>());
  }

  
  if(j.contains("access_token")){
    key.accessToken(j["access_token"].get<std::string>());
  }

  
  if(j.contains("access_token_secret")){
    key.accessTokenSecret(j["access_token_secret"].get<std::string>());
  }

return key;
}
} // namespace CocoaTweet::OAuth
