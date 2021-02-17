#include "cocoatweet/oauth/key.h"
#include "cocoatweet/api/api.h"

auto main() -> int {
  // キーオブジェクトを作成
  CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key::fromJsonFile("test.json");
  // 作成したキーオブジェクトを用いてAPIを立ち上げる．
  // 内部的にはキーオブジェクトを使用してOAuth認証機を立ち上げている．
  CocoaTweet::API::API api(key);

  api.status().Update("CocoaTwitterLibraryからテストツイートしています．\n昨日の反省を生かしてAPI-KeyをJsonファイルから読み込めるようにしたよ");
}
