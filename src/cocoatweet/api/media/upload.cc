#include <cocoatweet/api/media/upload.h>
#include <cocoatweet/api/model/mediaStore.h>
#include <fstream>
#include <iostream>

namespace CocoaTweet::API::Medias {
Upload::Upload() {
  url_ = "https://upload.twitter.com/1.1/media/upload.json";
}

void Upload::media(const std::string& _media) {
  media_ = _media;
}

void Upload::mediaId(const std::string& _mediaId) {}

CocoaTweet::API::Model::MediaStore Upload::process(
    std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth) {
  CocoaTweet::API::Model::MediaStore media;
  std::ifstream ifs(media_, std::ios::binary);
  ifs.seekg(0, std::ios::end);
  unsigned long long size = ifs.tellg();
  bodyParam_.insert_or_assign("total_bytes", std::to_string(size));
  ifs.seekg(0);
  std::string data((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
  ifs.close();

  // INIT
  {
    contentType_ = "application/x-www-form-urlencoded";
    bodyParam_.insert_or_assign("command", "INIT");
    bodyParam_.insert_or_assign("media_type", "image/jpeg");

    HttpPost::process(_oauth,
                      [&media](const unsigned int _responseCode, const std::string& _rsv) {
                        media = CocoaTweet::API::Model::MediaStore::parse(_responseCode, _rsv);
                      });

    bodyParam_.insert_or_assign("media_id", media.id());
  }

  // APPEND
  {
    contentType_ = "multipart/form-data";
    bodyParam_.erase("media_type");
    bodyParam_.erase("total_bytes");

    unsigned int segment           = 0;
    const unsigned long long chunk = 1024 * 512;
    while (segment * chunk < data.size()) {
      bodyParam_.insert_or_assign("command", "APPEND");
      bodyParam_.insert_or_assign("segment_index", std::to_string(segment));
      bodyParam_.insert_or_assign("media", data.substr(segment * chunk, chunk));
      HttpPost::process(_oauth, [](const unsigned int _responseCode, const std::string& _rsv) {
        // std::cout << _responseCode << std::endl << _rsv<< std::endl;
      });
      segment++;
    }
  }

  // FINALIZE
  {
    contentType_ = "application/x-www-form-urlencoded";
    bodyParam_.insert_or_assign("command", "FINALIZE");
    bodyParam_.erase("segment_index");
    bodyParam_.erase("media");
    HttpPost::process(_oauth,
                      [&media](const unsigned int _responseCode, const std::string& _rsv) {
                        media = CocoaTweet::API::Model::MediaStore::parse(_responseCode, _rsv);
                      });
  }

  // STATUS if needed
  {}

  return media;
}
} // namespace CocoaTweet::API::Medias
