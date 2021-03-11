#ifndef COCOATWEET_API_STATUS_STATUS_H_
#define COCOATWEET_API_STATUS_STATUS_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/oauth/oauth.h"
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>
namespace CocoaTweet::API::Statuses {
class Status : public groupInterface {
public:

struct Options{
  std::string replyToStatusId;
  bool autoPopulateReplyMetaData = false;
  std::vector<std::string> excludeReplyUserId;
  std::string attachmentUrl;
  std::pair<std::string, std::string> coord;
  bool displayCoord = false;
  bool trimUser = false;
  bool enableDMCommands = false;
  bool failDMCommands = true;
};
  Status() = default;
  Status(std::shared_ptr<CocoaTweet::OAuth::OAuth1> _oauth);
  CocoaTweet::API::Model::Tweet Update(const std::string& _status) const;

  CocoaTweet::API::Model::Tweet Update(const std::string& _status, const Options _options) const;

  CocoaTweet::API::Model::Tweet Update(const std::string& _status,
                                       std::vector<std::string> _mediaId) const;

  CocoaTweet::API::Model::Tweet Destroy(const std::string& _id) const;

private:
Options defaultOpt_;
};
} // namespace CocoaTweet::API::Statuses

#endif
