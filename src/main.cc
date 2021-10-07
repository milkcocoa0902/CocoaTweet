#include "cocoatweet/oauth/key.h"
#include "cocoatweet/api/api.h"
#include <cocoatweet/api/directMessage/new.h>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include <nlohmann/json.hpp>

#include <cocoatweet/exception/exception.h>
#include <cocoatweet/exception/rateLimitException.h>


bool starts_with(const std::string& s, const std::string& prefix) {
  auto size = prefix.size();
  if (s.size() < size) return false;
  return std::equal(std::begin(prefix), std::end(prefix), std::begin(s));
}

auto main() -> int {
  // Generate Key object
  // auto consumerKey           = "your consumer key";
  // auto consumerSecret        = "your consumer secret";
  // auto accessToken           = "your access token";
  // auto accessTokenSecret     = "your access token secret";
  // CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key(consumerKey,
  //                                                     consumerSecret,
  //                                                     accessToken,
  //                                                     accessTokenSecret);

  // also can generate Key object from JSON file
  CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key::fromJsonFile("api_key.json");
  // auto oauth = CocoaTweet::OAuth::OAuth1(key);
  // oauth.GenerateBearerToken(); 

  // std::cout << "sdfgwregfresgfresdwefgweragregreagretgreawgrt#$QTWREATGREWTGF$ERTF";
  // Generate API Entry object using Key object
  CocoaTweet::API::API api(key);
  // std::cout << api.generateBearerToken() << std::endl;

  // Now, you can use a twitter api
  // auto status = api.status().update("Hello Twitter World via Cocoa Twitter Library");
  // api.favorite().create(status.id());
  // api.favorite().destroy(status.id());
  // api.status().destroy(status.id());
  auto timeline = api.status().userTimeline("milkcocoa0902");
  std::cout << timeline[0].user().id();
}
