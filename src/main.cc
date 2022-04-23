#include <cocoatweet/api/api.h>
#include <iostream>
#include <cocoatweet/exception/exception.h>

#include <cocoatweet/api/oauth1/requestToken.h>
#include <cocoatweet/api/oauth1/authorize.h>
#include <cocoatweet/api/oauth1/accessToken.h>
#include <cocoatweet/api/oauth2/token.h>
#include <cocoatweet/authentication/oauth.h>

#include <cocoatweet/util/util.h>

auto main() -> int {
  // Generate Key object
  // auto consumerKey           = "your consumer key";
  // auto consumerSecret        = "your consumer secret";
  // auto accessToken           = "your access token";
  // auto accessTokenSecret     = "your access token secret";
  // CocoaTweet::Authentication::Key key = CocoaTweet::Authentication::Key(consumerKey,
  //                                                     consumerSecret,
  //                                                     accessToken,
  //                                                     accessTokenSecret);

  try {
    // also can generate Key object from JSON file
    CocoaTweet::Authentication::Key key =
        CocoaTweet::Authentication::Key::fromJsonFile("api_key.json");

    // Generate API Entry object using Key object
    CocoaTweet::API::API api(key);

    // Now, you can use a twitter api
    // auto status = api.status().update("Hello Twitter World via Cocoa Twitter Library!!");
    // std::cout << status.id() << std::endl;
    // api.favorite().create(status.id());
    // api.favorite().destroy(status.id());
    // api.status().destroy(status.id());
    // auto timeline = api.status().userTimeline("milkcocoa0902");
  } catch (CocoaTweet::Exception::Exception e) {
    std::cout << e.what() << std::endl;
  }
}
