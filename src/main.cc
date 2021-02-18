#include "cocoatweet/oauth/key.h"
#include "cocoatweet/api/api.h"

auto main() -> int {
  // キーオブジェクトを作成
  // auto consumerKey = "your consumer key";
  // auto consumerSecret = "your consumer secret";
  // auto accessToken = "your access token";
  // auto accessTokenSecret = "your access token secret";
  // CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key(consumerKey, consumerSecret,
  // accessToken, accessTokenSecret);

  // jsonファイルから各種キーを読み込むことも可能
  CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key::fromJsonFile("apikey.json");

  // 作成したキーオブジェクトを用いてAPIを立ち上げる．
  // 内部的にはキーオブジェクトを使用してOAuth認証機を立ち上げている．
  CocoaTweet::API::API api(key);

  api.status().Update("Hello Twitter World from Cocoa Twitter Library");
}
