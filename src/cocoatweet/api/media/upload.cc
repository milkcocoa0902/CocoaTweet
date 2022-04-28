#include <cocoatweet/api/media/upload.h>
#include <cocoatweet/api/model/mediaStore.h>
#include <cocoatweet/exception/unsupportedMediaTypeException.h>
#include <fstream>
namespace CocoaTweet::API::Medias {
const std::map<std::string, std::string> Upload::mimeType = {{".jpg", "image/jpeg"},
                                                             {".jpeg", "image/jpeg"},
                                                             {".png", "image/png"},
                                                             {".gif", "image/gif"},
                                                             {".mp4", "video/mp4"}};
Upload::Upload() {
  url_ = "https://upload.twitter.com/1.1/media/upload.json";
}

void Upload::media(const std::string& _media) {
  media_ = _media;
}

void Upload::mediaId(const std::string& _mediaId) {}

CocoaTweet::API::Model::MediaStore Upload::process(
    std::weak_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth) {
  auto extension = std::filesystem::path(media_).extension().string<char>();
  if (mimeType.count(extension) == 0) {
    throw new CocoaTweet::Exception::UnsupportedMediaTypeException(
        std::string("media type \"" + extension + "\" is not supported media type"));
  }

  auto backup = bodyParam_;
  CocoaTweet::API::Model::MediaStore media;
  std::ifstream ifs(media_, std::ios::binary);
  std::string data((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
  ifs.close();

  bodyParam_.insert_or_assign("total_bytes", std::to_string(data.size()));

  // INIT
  {
    contentType_ = "application/x-www-form-urlencoded";
    bodyParam_.insert_or_assign("command", "INIT");
    bodyParam_.insert_or_assign(
        "media_type", mimeType.at(std::filesystem::path(media_).extension().string<char>()));

    HttpPost::process(_oauth, [&media](const std::string& _rcv) {
      media = CocoaTweet::API::Model::MediaStore::parse(_rcv);
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
      HttpPost::process(_oauth, [](const std::string& _rsv) {
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
    HttpPost::process(_oauth, [&media](const std::string& _rcv) {
      media = CocoaTweet::API::Model::MediaStore::parse(_rcv);
    });
  }

  // STATUS if needed
  {}

  bodyParam_ = backup;

  return media;
}
} // namespace CocoaTweet::API::Medias
