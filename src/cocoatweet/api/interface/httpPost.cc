#include <cocoatweet/api/interface/httpPost.h>
#include "cocoatweet/util/util.h"
#include <cocoatweet/exception/tweetNotFoundException.h>
#include <cocoatweet/exception/authenticateException.h>
#include <cocoatweet/exception/tweetDuplicateException.h>
#include <cocoatweet/exception/tweetTooLongException.h>
#include <cocoatweet/exception/rateLimitException.h>
#include "nlohmann/json.hpp"
#include <iterator>
#include <memory>
#include <vector>
#include <sstream>
#include <stdexcept>
extern "C" {
#include <curl/curl.h>
}

#ifndef NDEBUG
#include <iostream>
#endif

namespace CocoaTweet::API::Interface {
void HttpPost::process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth,
                       std::function<void(const std::string&)> _callback) {
  // エンドポイントへのパラメータにOAuthパラメータを付加して署名作成
  auto oauth       = _oauth.lock();
  auto oauthParam  = oauth->oauthParam();
  auto sigingParam = oauthParam;
  if (contentType_ == "application/x-www-form-urlencoded") {
    for (const auto [k, v] : bodyParam_) {
      sigingParam.insert_or_assign(k, v);
    }
  }

  auto signature = oauth->signature(sigingParam, "POST", url_);

  // 作成した署名をエンドポイントへのパラメータ及びOAuthパラメータに登録
  oauthParam.merge(signature);

  // リクエストボディの構築
  std::string requestBody = "";
  {
    if (contentType_ == "application/x-www-form-urlencoded") {
      std::vector<std::string> tmp;
      for (const auto& [key, value] : bodyParam_) {
        tmp.push_back(key + "=" + value);
        requestBody = CocoaTweet::Util::join(tmp, "&");
      }
    } else if (contentType_ == "multipart/form-data") {
      for (const auto& [key, value] : bodyParam_) {
        requestBody += (std::string("--") + "milkcocoa0902" + "\r\n");
        requestBody +=
            ("Content-Disposition: form-data; name=\"" + key + "\";\r\n\r\n" + value + "\r\n");
      }
      requestBody += (std::string("--") + "milkcocoa0902" + "--" + "\r\n");
    }else if(contentType_ == "application/json"){
      requestBody = bodyParam_["data"];
    }
  }

  // ヘッダの構築
  std::string oauthHeader = "authorization: OAuth ";
  {
    std::vector<std::string> tmp;
    for (const auto& [key, value] : oauthParam) {
      tmp.push_back(key + "=" + CocoaTweet::Util::urlEncode(value));
    }
    oauthHeader += CocoaTweet::Util::join(tmp, ",");
  }

  // do post
  CURL* curl;
  CURLcode res;
  std::string rcv;
  long responseCode;
  curl = curl_easy_init();
  url_ = url_;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url_.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestBody.length());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback_);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (std::string*)&rcv);
#ifndef NDEBUG
    std::cout << "requestBody : " << requestBody << std::endl;
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
#endif
    // Headerを保持するcurl_slist*を初期化
    struct curl_slist* headers = NULL;
    // Authorizationをヘッダに追加
    headers = curl_slist_append(headers, oauthHeader.c_str());

    std::string contentType = "";
    if (contentType_ == "application/x-www-form-urlencoded") {
      contentType = contentType_;
    } else if (contentType_ == "multipart/form-data") {
      contentType = contentType_ + "; boundary=milkcocoa0902";
    }else if(contentType_ == "application/json"){
      contentType_ = "application/json";
    }

    headers = curl_slist_append(headers, ("Content-Type: " + contentType).c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
    curl_easy_cleanup(curl);
  }

  if (res != CURLE_OK) {
    throw std::runtime_error(std::string("INTERNAL ERROR : curl(") + std::to_string(res) + ")");
    exit(1);
  }

  if ((responseCode / 100) == 4) {
    auto j       = nlohmann::json::parse(rcv);
    auto error   = j["errors"][0]["code"];
    auto message = j["errors"][0]["message"];
    if (j.count("error") != 0) {
      // この形式はエラーコードを持たないのでエラー種別が特定できない
      throw new CocoaTweet::Exception::Exception(j["error"]);
    }
    if (error.get<int>() == 144) {
      throw CocoaTweet::Exception::TweetNotFoundException(message.get<std::string>().c_str());
    } else if (error.get<int>() == 32) {
      throw CocoaTweet::Exception::AuthenticateException(message.get<std::string>().c_str());
    } else if (error.get<int>() == 187) {
      throw CocoaTweet::Exception::TweetDuplicateException(message.get<std::string>().c_str());
    } else if (error.get<int>() == 88 || error.get<int>() == 185) {
      throw CocoaTweet::Exception::RateLimitException(message.get<std::string>().c_str());
    } else if (error.get<int>() == 186) {
      throw CocoaTweet::Exception::TweetTooLongException(message.get<std::string>().c_str());
    }
  }

  if (_callback) {
    _callback(rcv);
  }
}
} // namespace CocoaTweet::API::Interface
