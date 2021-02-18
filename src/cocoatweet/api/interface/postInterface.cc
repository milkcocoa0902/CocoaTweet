#include <cocoatweet/api/interface/postInterface.h>
#include "cocoatweet/util/util.h"
#include <iterator>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
extern "C" {
#include <curl/curl.h>
}

namespace CocoaTweet::API::Interface {
size_t postInterface::curlCallback_(char* _ptr, size_t _size, size_t _nmemb,
                                    std::string* _stream) {
  int realsize = _size * _nmemb;
  _stream->append(_ptr, realsize);
  return realsize;
}

void postInterface::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth,
                     std::function<void(std::string)> _callback) {
  // エンドポイントへのパラメータにOAuthパラメータを付加して署名作成
  auto oauth       = _oauth.lock();
  auto oauthParam  = oauth->oauthParam();
  auto sigingParam = oauthParam;
  for (const auto [k, v] : bodyParam_) {
    sigingParam.insert_or_assign(k, v);
  }

  auto signature = oauth->signature(sigingParam, "POST", url_);

  // 作成した署名をエンドポイントへのパラメータ及びOAuthパラメータに登録
  std::cout << "signature : " << signature["oauth_signature"] << std::endl;
  oauthParam.merge(signature);

  // リクエストボディの構築
  std::string requestBody = "";
  {
    std::vector<std::string> tmp;
    for (const auto& [key, value] : bodyParam_) {
      tmp.push_back(key + "=" + value);
    }
    std::stringstream os;
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<std::string>(os, "&"));
    requestBody = os.str();
    requestBody.erase(requestBody.size() - std::char_traits<char>::length("&"));
  }
  std::cout << "request Body -> " << requestBody << std::endl;

  // ヘッダの構築
  std::string oauthHeader = "authorization: OAuth ";
  {
    std::vector<std::string> tmp;
    for (const auto& [key, value] : oauthParam) {
      tmp.push_back(key + "=" + CocoaTweet::Util::urlEncode(value));
    }
    std::stringstream os;
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<std::string>(os, ","));
    oauthHeader += os.str();
    oauthHeader.erase(oauthHeader.size() - std::char_traits<char>::length(","));
  }
  std::cout << "OAuth Header -> " << oauthHeader << std::endl;

  // do post
  CURL* curl;
  CURLcode res;
  std::string rcv;
  curl = curl_easy_init();
  url_ = url_; // + "?status=" + status_;
  std::cout << "URL : " << url_ << std::endl;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url_.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestBody.length());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback_);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (std::string*)&rcv);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    // Headerを保持するcurl_slist*を初期化
    struct curl_slist* headers = NULL;
    // Authorizationをヘッダに追加
    headers = curl_slist_append(headers, oauthHeader.c_str());
    // headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
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
} // namespace CocoaTweet::API::Interface
