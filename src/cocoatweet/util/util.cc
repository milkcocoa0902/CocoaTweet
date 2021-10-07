#include "cocoatweet/util/util.h"
#include <cctype>
#include <iomanip>

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

} // namespace CocoaTweet::Util
