#include <cocoatweet/api/interface.h>

namespace CocoaTweet::API{
		size_t Interface::curlCallback_(char* _ptr, size_t _size, size_t _nmemb, std::string* _stream){
			int realsize = _size * _nmemb;
    		_stream->append(_ptr, realsize);
    		return realsize;
		}
}
