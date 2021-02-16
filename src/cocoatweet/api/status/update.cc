#include "cocoatweet/api/status/update.h"
#include "cocoatweet/util/util.h"
#include <iterator>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
extern "C" {
#include <curl/curl.h>
}

namespace CocoaTweet::API::Statuses {
Update::Update() {
  url_ = "https://api.twitter.com/1.1/statuses/update.json";
}
void Update::status(const std::string _status) {
  status_ = _status;
  param_.insert_or_assign("status", status_);
}

void Update::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth,
                     std::function<void(std::string)> _callback) {
  // エンドポイントへのパラメータにOAuthパラメータを付加して署名作成
  auto oauth = _oauth.lock();
  param_.merge(oauth->oauthParam());
  auto signature = oauth->signature(param_, "POST", url_);

  // 作成した署名をエンドポイントへのパラメータ及びOAuthパラメータに登録
  param_.insert_or_assign("oauth_signature", signature["oauth_signature"]);
  auto header = oauth->oauthParam();
  std::cout << "signature : " << signature["oauth_signature"] << std::endl;
  header.insert_or_assign("oauth_signature", signature["oauth_signature"]);

  // リクエストボディの構築
  std::string requestBody = "";
  {
    std::vector<std::string> tmp;
    for (const auto& [key, value] : param_) {
      tmp.push_back(key + "=" + value);
    }
    std::stringstream os;
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<std::string>(os, "&"));
    requestBody = os.str();
    requestBody.erase(requestBody.size() - std::char_traits<char>::length("&"));
  }
	requestBody += (std::string("&") + "oauth_signature=" + signature["oauth_signature"]);
  std::cout << "request Body -> " << requestBody << std::endl;

  // ヘッダの構築
  std::string oauthHeader = "Authorization: OAuth ";
  {
    std::vector<std::string> tmp;
    for (const auto& [key, value] : header) {
      tmp.push_back(key + "=" + value);
    }
    std::stringstream os;
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<std::string>(os, ","));
    oauthHeader += os.str();
    oauthHeader.erase(oauthHeader.size() - std::char_traits<char>::length(","));
  }
	//oauthHeader += (std::string(",") + "oauth_signature=" + signature["oauth_signature"]);
  std::cout << "OAuth Header -> " << oauthHeader << std::endl;

  // do post
  CURL* curl;
  CURLcode res;
  std::string rcv;
  curl = curl_easy_init();
  std::cout << "URL : " << url_ << std::endl;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url_.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestBody.length());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback_);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (std::string*)&rcv);
    curl_easy_setopt(curl, CURLOPT_PROXY, "");
    // Headerを保持するcurl_slist*を初期化
    struct curl_slist* headers = NULL;
    // Authorizationをヘッダに追加
    headers = curl_slist_append(headers, oauthHeader.c_str());
    curl_easy_setopt(curl, CURLOPT_HEADER, headers);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
  if (res != CURLE_OK) {
    std::cout << "curl error : " << res << std::endl;
    exit(1);
  }

  if (_callback) {
    _callback(rcv);
  }
}
} // namespace CocoaTweet::API::Statuses
