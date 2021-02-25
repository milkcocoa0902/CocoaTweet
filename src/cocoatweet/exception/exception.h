#ifndef COCOATWEET_EXCEPTION_EXCEPTION_H_
#define COCOATWEET_EXCEPTION_EXCEPTION_H_

#include <string>
#include <exception>

namespace CocoaTweet::Exception {
class Exception : public std::exception {
public:
  Exception(const char* _msg) : msg_(std::string(_msg)) {}
  const std::string& what() {
    return msg_;
  }
  virtual ~Exception() = default;

protected:
  std::string msg_;
};
} // namespace CocoaTweet::Exception

#endif
