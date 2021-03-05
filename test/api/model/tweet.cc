#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "nlohmann/json.hpp"
#include "cocoatweet/api/model/tweet.h"
#include "cocoatweet/exception/authenticateException.h"
#include "cocoatweet/exception/rateLimitException.h"
#include "cocoatweet/exception/tweetTooLongException.h"
#include "cocoatweet/exception/tweetDuplicateException.h"

BOOST_AUTO_TEST_SUITE(tweet_object)
BOOST_AUTO_TEST_CASE(test01) {
  CocoaTweet::API::Model::Tweet tweet;

  BOOST_TEST(tweet.id() == "");
  BOOST_TEST(tweet.createdAt() == "");
  BOOST_TEST(tweet.text() == "");
  BOOST_TEST(tweet.source() == "");
}

BOOST_AUTO_TEST_CASE(test02) {
  std::string json = R"({
    "id_str" : "1234567890",
    "created_at" : "Thu Mar 04 00:00:00 +0000 2021",
    "text" : "tweet",
    "source" : "Twitter for Android"
  })";

  CocoaTweet::API::Model::Tweet tweet(200, json);
  BOOST_TEST(tweet.id() == "1234567890");
  BOOST_TEST(tweet.createdAt() == "Thu Mar 04 00:00:00 +0000 2021");
  BOOST_TEST(tweet.text() == "tweet");
  BOOST_TEST(tweet.source() == "Twitter for Android");
}

BOOST_AUTO_TEST_CASE(test03) {
  std::string json = R"({
  "errors" : [{
    "code" : 32,
    "message" : "Could not authenticate you."
    }]
  })";

  BOOST_CHECK_THROW(CocoaTweet::API::Model::Tweet(401, json), CocoaTweet::Exception::AuthenticateException);
}

BOOST_AUTO_TEST_CASE(test04) {
  std::string json = R"({
  "errors" : [{
    "code" : 88,
    "message" : "Rate limit exceeded."
    }]
  })";

  BOOST_CHECK_THROW(CocoaTweet::API::Model::Tweet(429, json), CocoaTweet::Exception::RateLimitException);
}

BOOST_AUTO_TEST_CASE(test05) {
  std::string json = R"({
  "errors" : [{
    "code" : 185,
    "message" : "User is over daily status update limit."
    }]
  })";

  BOOST_CHECK_THROW(CocoaTweet::API::Model::Tweet(403, json), CocoaTweet::Exception::RateLimitException);
}

BOOST_AUTO_TEST_CASE(test06) {
  std::string json = R"({
  "errors" : [{
    "code" : 186,
    "message" : "Tweet needs to be a bit shorter."
    }]
  })";

  BOOST_CHECK_THROW(CocoaTweet::API::Model::Tweet(403, json), CocoaTweet::Exception::TweetTooLongException);
}

BOOST_AUTO_TEST_CASE(test07) {
  std::string json = R"({
  "errors" : [{
    "code" : 187,
    "message" : "Status is a duplicate."
    }]
  })";

  BOOST_CHECK_THROW(CocoaTweet::API::Model::Tweet(403, json), CocoaTweet::Exception::TweetDuplicateException);
}
BOOST_AUTO_TEST_SUITE_END()
