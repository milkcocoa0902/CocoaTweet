#include "cocoatweet/oauth/key.h"
#include "cocoatweet/api/api.h"

// 下記で使用しているAPI Keyはほぼ本物です．
// (再生成したので使用できないが，こんな感じで登録)
auto main() -> int {
  auto consumerKey       = "JRKUmkKFWiC3f7K6msLKaNNuP";
  auto consumerSecret    = "dTGI49MHRqa7XIFiPjwJR27vwolzsRaRXKA48iFlwAv4LK9Vlm";
  auto accessToken       = "2224351076-uF2XTmYeDdAfIsixuvfrwt8puLiPuwGe4w7RM8I";
  auto accessTokenSecret = "dpCctbxzMjQ9AjZ6V7Fs6TIQlpPJo7JEkmjMfSO7QCEpW";

  // キーオブジェクトを作成
  CocoaTweet::OAuth::Key key(consumerKey, consumerSecret, accessToken, accessTokenSecret);

  // 作成したキーオブジェクトを用いてAPIを立ち上げる．
  // 内部的にはキーオブジェクトを使用してOAuth認証機を立ち上げている．
  CocoaTweet::API::API api(key);

  // クエリ文字列をURLエンコードしてないので，空白とか日本語とかはまだ無理．
  api.status().Update("test");
}
