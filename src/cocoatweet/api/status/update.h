#ifndef COCOATWEET_API_STATUS_UPDATE_H_
#define COCOATWEET_API_STATUS_UPDATE_H_

#include <cocoatweet/api/interface/httpPost.h>
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>
#include <memory>

namespace CocoaTweet::API::Statuses {
/// @brief class for using statuses/update endpoint
class Update : public CocoaTweet::API::Interface::HttpPost {
public:
  /// @brief primary constructor
  Update();

  /// @brief set tweet text for sending request to statuses/update
  /// @param[in] const std::string _status : tweet text
  /// @param[out] none
  void status(const std::string _status);

  void mediaId(const std::vector<std::string> _media);

  void replyToStatusId(const std::string _reply);

  void autoPopulateReplyMetaData(bool _meta);

  void excludeReplyUserId(const std::vector<std::string> _ex);

  void attachmentUrl(const std::string _url);

  void coord(std::pair<std::string, std::string> _coord);

  void displayCoord(bool _disp);

  void trimUser(bool _trim);

  void enableDMCommands(bool _enable);

  void failDMCommands(bool _fail);

  /// @brief process request for endpoint
  /// @param[in] std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth : pointer to oauth object
  /// @param[out] CocoaTweet::API::Model::Tweet : request result
  CocoaTweet::API::Model::Tweet process(std::weak_ptr<CocoaTweet::OAuth::OAuth1> _oauth);

private:
  std::string status_;
};
} // namespace CocoaTweet::API::Statuses

#endif
