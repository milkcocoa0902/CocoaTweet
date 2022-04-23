#include <cocoatweet/api/api.h>
#include <iostream>
#include <cocoatweet/exception/exception.h>

#include <cocoatweet/api/oauth1/requestToken.h>
#include <cocoatweet/api/oauth1/authorize.h>
#include <cocoatweet/api/oauth1/accessToken.h>
#include <cocoatweet/api/oauth2/token.h>
#include <cocoatweet/authentication/authenticate.h>

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
    std::shared_ptr<CocoaTweet::Authentication::OAuth1> oauth =
        std::make_shared<CocoaTweet::Authentication::OAuth1>(key);

    // Generate API Entry object using Key object
    CocoaTweet::API::API api(key);
    auto bearerToken = api.oauth2().token();
    key.bearerToken(bearerToken);
    key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH2);
    api.swapKey(key);

    auto user = api.user().show("milkcocoa9692");
    std::cout << user.id() << std::endl;
    // api.directMessage().messageCreate(
    //     user.id(),
    //     "これはクソみたいなスパムDMです。\nCocoaTwitterLibraryで、user/"
    //     "showが叩けるようになったので、外部サービスでuser_idを調べずともscreen_"
    //     "nameで引っ張ってきてクソDMを投げられるようになりました👏\nその記念にAPIから発砲🔫←センス最"
    //     "悪\nhttps://github.com/koron0902/CocoaTweet");
    // if you want to access api using Bearer Token, call this for get BearerToken;
    // NOTE: call this, always authenticate with Bearer Token, which is Read Only Token
    // try {
    // api.generateBearerToken();

    // Now, you can use a twitter api
    auto status = api.status().update("Hello Twitter World via Cocoa Twitter Library!!");
    // std::cout << status.id() << std::endl;
    // api.favorite().create(status.id());
    // api.favorite().destroy(status.id());
    // api.status().destroy(status.id());
    // auto timeline = api.status().userTimeline("milkcocoa0902");
  } catch (CocoaTweet::Exception::Exception e) {
    std::cout << e.what() << std::endl;
  }
}
