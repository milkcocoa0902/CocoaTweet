#include <cocoatweet/api/interface/postInterface.h>

namespace CocoaTweet::API::Interface {
size_t postInterface::curlCallback_(char* _ptr, size_t _size, size_t _nmemb,
                                    std::string* _stream) {
  int realsize = _size * _nmemb;
  _stream->append(_ptr, realsize);
  return realsize;
}
} // namespace CocoaTweet::API::Interface
