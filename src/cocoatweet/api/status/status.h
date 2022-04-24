#ifndef COCOATWEET_API_STATUS_STATUS_H_
#define COCOATWEET_API_STATUS_STATUS_H_

#include "cocoatweet/api/interface/groupInterface.h"
#include "cocoatweet/authentication/authenticator.h"
#include <cocoatweet/api/model/tweet.h>
#include <vector>
#include <utility>

namespace CocoaTweet::API::Statuses {

/// @brief Entory point for statuses/*
class Status : public groupInterface {
public:
  struct Options {
    std::string replyToStatusId;
    bool autoPopulateReplyMetaData = false;
    std::vector<std::string> excludeReplyUserId;
    std::string attachmentUrl;
    std::pair<std::string, std::string> coord;
    bool displayCoord     = false;
    bool trimUser         = false;
    bool enableDMCommands = false;
    bool failDMCommands   = true;
  };

  /// @brief  primary constructor to allow for create NON-INITIALIZED object
  Status() = default;

  /// @brief   constructor which finally should to be called.
  /// @param[in] std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> : pointer to
  /// OAuth object
  Status(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth);

  /// @brief send request to statuses/update with specified status
  /// @details this function throws CocoaTweet::Exception::* if something happen
  /// @param[in] const std::string& : tweet text
  /// @param[out] CocoaTweet::API::Model::Tweet : Tweet result
  CocoaTweet::API::Model::Tweet update(const std::string& _status) const;

  /// @brief send request to statuses/update with specified status
  /// @details this function throws CocoaTweet::Exception::* if something happen
  /// @param[in] const std::string& : tweet text
  /// @param[in] const CocoaTweet::API::Statuses::Status::Options option : status update options
  /// for more parameters
  /// @param[out] CocoaTweet::API::Model::Tweet : Tweet result
  CocoaTweet::API::Model::Tweet update(const std::string& _status,
                                       const Options _options) const;

  /// @brief send request to statuses/update with specified status
  /// @details this function throws CocoaTweet::Exception::* if something happen
  /// @param[in] const std::string& : tweet text
  /// @param[in] std::vector<std::string> _mediaId : media id which posted with tweet
  /// @param[out] CocoaTweet::API::Model::Tweet : Tweet result
  CocoaTweet::API::Model::Tweet update(const std::string& _status,
                                       std::vector<std::string> _mediaId) const;

  /// @brief send request to statuses/destroy with specified id
  /// @details this function throws CocoaTweet::Exception::* if something happen
  /// @param[in] const std::string& : tweet id which should be delete
  /// @param[out] CocoaTweet::API::Model::Tweet : Destroy result
  CocoaTweet::API::Model::Tweet destroy(const std::string& _id) const;

  CocoaTweet::API::Model::Tweet retweet(const std::string& _id) const;
  CocoaTweet::API::Model::Tweet unretweet(const std::string& _id) const;

  std::vector<CocoaTweet::API::Model::Tweet> userTimeline(const std::string& _screenName) const;

private:
  Options defaultOpt_;
};
} // namespace CocoaTweet::API::Statuses

#endif
