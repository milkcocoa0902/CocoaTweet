#ifndef COCOATWEET_UTIL_UTIL_H_
#define COCOATWEET_UTIL_UTIL_H_

#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

namespace CocoaTweet::Util {
std::string urlEncode(const std::string& _str);
std::string urlDecode(const std::string& _str);
std::string join(const std::vector<std::string> _vec, const std::string& _delim);
std::unordered_map<std::string, std::string> parse(const std::string str, const char _delim,
                                                   const char _conn);
} // namespace CocoaTweet::Util

#endif
