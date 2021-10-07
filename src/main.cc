#include <cocoatweet/api/api.h>
#include <iostream>
#include <cocoatweet/exception/exception.h>

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
  // try {
    // api.generateBearerToken();

    // Now, you can use a twitter api
    // auto status = api.status().update("Hello Twitter World via Cocoa Twitter Library");
    // api.favorite().create(status.id());
    // api.favorite().destroy(status.id());
    // api.status().destroy(status.id());
    // auto timeline = api.status().userTimeline("milkcocoa0902");
  // } catch (CocoaTweet::Exception::Exception e) {
  //   std::cout << e.what() << std::endl;
  // }
}
