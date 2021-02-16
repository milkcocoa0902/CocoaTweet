#ifndef COCOATWEET_UTIL_UTIL_H_
#define COCOATWEET_UTIL_UTIL_H_

#include <vector>
#include <string>
#include <sstream>

namespace CocoaTweet::Util{
	std::string urlEncode(const std::string& _str);
	template<typename T>
	std::string join(const std::vector<T> _vec);
}

#endif
