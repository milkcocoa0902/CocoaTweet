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
  // CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key::fromJsonFile("api_key.json");

  // Generate API Entry object using Key object
  // CocoaTweet::API::API api(key);

  // if you want to access api using Bearer Token, call this for get BearerToken;
  // NOTE: call this, always authenticate with Bearer Token, which is Read Only Token
  // api.generateBearerToken();

  // Now, you can use a twitter api
  // auto status = api.status().update("Hello Twitter World via Cocoa Twitter Library");
  // api.favorite().create(status.id());
  // api.favorite().destroy(status.id());
  // api.status().destroy(status.id());
  // auto timeline = api.status().userTimeline("milkcocoa0902");
}
