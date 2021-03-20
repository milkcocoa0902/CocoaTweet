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

  CocoaTweet::API::Model::Tweet tweet(json);
  BOOST_TEST(tweet.id() == "1234567890");
  BOOST_TEST(tweet.createdAt() == "Thu Mar 04 00:00:00 +0000 2021");
  BOOST_TEST(tweet.text() == "tweet");
  BOOST_TEST(tweet.source() == "Twitter for Android");
}

BOOST_AUTO_TEST_SUITE_END()
