#include "cocoatweet/oauth/key.h"
#include "cocoatweet/api/api.h"

auto main() -> int {
  auto consumerKey       = "JRKUmkKFWiC3f7K6msLKaNNuP";
  auto consumerSecret    = "dTGI49MHRqa7XIFiPjwJR27vwolzsRaRXKA48iFlwAv4LK9Vlm";
  auto accessToken       = "2224351076-uF2XTmYeDdAfIsixuvfrwt8puLiPuwGe4w7RM8I";
  auto accessTokenSecret = "dpCctbxzMjQ9AjZ6V7Fs6TIQlpPJo7JEkmjMfSO7QCEpW";
  CocoaTweet::OAuth::Key key(consumerKey, consumerSecret, accessToken, accessTokenSecret);
  CocoaTweet::API::API api(key);
  api.status().Update("tweet_from_Cocoa_Twitter_Library");
}
