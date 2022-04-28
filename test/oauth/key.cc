#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include "cocoatweet/authentication/key.h"

BOOST_AUTO_TEST_SUITE(oauth_key)
BOOST_AUTO_TEST_CASE(test01) {
  CocoaTweet::Authentication::Key key;

  BOOST_TEST(key.consumerKey() == "");
  BOOST_TEST(key.consumerSecret() == "");
  BOOST_TEST(key.accessToken() == "");
  BOOST_TEST(key.accessTokenSecret() == "");
}

BOOST_AUTO_TEST_CASE(test02) {
  CocoaTweet::Authentication::Key key("consumerKey", "consumerSecret", "accessToken",
                                      "accessTokenSecret");

  BOOST_TEST(key.consumerKey() == "consumerKey");
  BOOST_TEST(key.consumerSecret() == "consumerSecret");
  BOOST_TEST(key.accessToken() == "accessToken");
  BOOST_TEST(key.accessTokenSecret() == "accessTokenSecret");

  auto noSecret = key.noSecret();
  BOOST_TEST(noSecret.at("oauth_consumer_key") == "consumerKey");
  BOOST_TEST(noSecret.at("oauth_token") == "accessToken");

  auto secret = key.secret();
  BOOST_TEST(secret.at("oauth_consumer_key") == "consumerSecret");
  BOOST_TEST(secret.at("oauth_token") == "accessTokenSecret");
}

BOOST_AUTO_TEST_SUITE_END()
