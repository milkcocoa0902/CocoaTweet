#include "cocoatweet/util/util.h"
#include <cctype>
#include <iomanip>
#include <vector>

#include <iostream>

namespace CocoaTweet::Util {
std::string urlEncode(const std::string& _str) {
  std::stringstream out;

  for (const auto c : _str) {
    if (std::isalpha(c) || std::isdigit(c) ||
        (c == '.' || (c == '_') || (c == '-' || (c == '~')))) {
      out << c;
    } else {
      out << '%' << std::setw(2) << std::setfill('0') << std::hex << std::uppercase
          << (0xFF & static_cast<int>(c));
    }
  }

  return out.str();
}

std::string urlDecode(const std::string& _str) {
  std::stringstream out;
  int first = 0;
  int last  = _str.find_first_of('%');

  while (first < _str.size()) {
    if (last == std::string::npos) {
      out << _str.substr(first);
      break;
    }

    auto s       = _str.substr(first, last - first);
    auto encoded = _str.substr(last + 1, 2); // %を飛ばし読みする

    std::cout << encoded << std::endl;
    auto c = static_cast<char>(static_cast<int>(strtol(encoded.c_str(), nullptr, 16)));

    out << s << c;

    first = last + 3;
    last  = _str.find_first_of('%', first);
  }

  return out.str();
}

std::string join(const std::vector<std::string> _vec, const std::string& _delim) {
  std::string str("");

  for (auto v : _vec) {
    str += (v + _delim);
  }

  if (!str.empty()) {
    str.pop_back();
  }

  return str;
}

std::unordered_map<std::string, std::string> parse(const std::string str, const char _delim,
                                                   const char _conn) {
  int first = 0;
  int last  = str.find_first_of(_delim);
  std::vector<std::string> result;

  while (first < str.size()) {
    result.push_back(str.substr(first, last - first));
    first = last + 1;
    last  = str.find_first_of(_delim, first);
    if (last == std::string::npos) last = str.size();
  }

  auto mp = std::unordered_map<std::string, std::string>();
  for (auto elm : result) {
    int pos = elm.find_first_of(_conn);

    std::cout << pos << std::endl;
    if (pos == std::string::npos) {
      mp.insert_or_assign(elm, "");
    } else {
      auto key = elm.substr(0, pos);
      auto val = elm.substr(pos + 1);
      mp.insert_or_assign(key, val);
    }
  }

  return mp;
}

} // namespace CocoaTweet::Util
