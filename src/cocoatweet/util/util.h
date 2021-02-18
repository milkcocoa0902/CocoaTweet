#ifndef COCOATWEET_UTIL_UTIL_H_
#define COCOATWEET_UTIL_UTIL_H_

#include <vector>
#include <string>
#include <sstream>

namespace CocoaTweet::Util {
std::string urlEncode(const std::string& _str);
std::string join(const std::vector<std::string> _vec, const std::string& _delim);
} // namespace CocoaTweet::Util

#endif
