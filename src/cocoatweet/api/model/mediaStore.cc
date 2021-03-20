#include <cocoatweet/api/model/mediaStore.h>
#include <cocoatweet/exception/exception.h>
#include "nlohmann/json.hpp"

namespace CocoaTweet::API::Model {
MediaStore MediaStore::parse(const std::string& _json) {
  auto j = nlohmann::json::parse(_json);
  MediaStore media;

  if (j.count("media_id_string") != 0) {
    media.id(j["media_id_string"]);
  }

  if (j.count("size") != 0) {
    media.size(j["size"]);
  }

  if (j.count("expires_after_secs") != 0) {
    media.expires(j["expires_after_secs"]);
  }

  if (j.count("processing_info") == 0) {
    media.state("succeeded");
  } else {
    media.state(j["processing_info"]["state"]);
    media.remain(j["processing_info"]["check_after_secs"].get<unsigned int>());
  }

  return media;
}

void MediaStore::id(const std::string _id) {
  id_ = _id;
}

void MediaStore::size(const unsigned int _size) {
  size_ = _size;
}

void MediaStore::expires(const unsigned int _ex) {
  expires_ = _ex;
}
void MediaStore::state(const std::string _state) {
  state_ = _state;
}

void MediaStore::remain(const unsigned int _remain) {
  remain_ = _remain;
}

const std::string MediaStore::id() const {
  return id_;
}
const unsigned int MediaStore::size() const {
  return size_;
}
const unsigned int MediaStore::expire() const {
  return expires_;
}
const std::string MediaStore::state() const {
  return state_;
}

const unsigned int MediaStore::remain() const {
  return remain_;
}
} // namespace CocoaTweet::API::Model
