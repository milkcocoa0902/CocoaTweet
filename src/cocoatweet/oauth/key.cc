#include "cocoatweet/oauth/key.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>

namespace CocoaTweet::OAuth {
Key Key::fromJsonFile(const std::string _jsonFile) {
  std::ifstream ifs(_jsonFile);
  std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

  auto j = nlohmann::json::parse(str);
  return Key(j["consumer_key"], j["consumer_secret"], j["access_token"],
             j["access_token_secret"]);
}
} // namespace CocoaTweet::OAuth
