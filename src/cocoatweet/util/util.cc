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

template <typename T>
std::string join(const std::vector<T> _vec) {}
} // namespace CocoaTweet::Util
