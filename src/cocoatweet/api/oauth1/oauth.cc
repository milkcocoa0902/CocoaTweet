#include <cocoatweet/api/oauth1/oauth.h>
#include <cocoatweet/authentication/authenticate.h>

namespace CocoaTweet::API::OAuth1 {
  OAuth::OAuth(std::shared_ptr<CocoaTweet::Authentication::AuthenticatorBase> _oauth){
      oauth_ = _oauth;
  }

  CocoaTweet::API::Model::OAuthToken OAuth::requestToken(const std::string& _oauthCallback) const{
      auto key = oauth_.lock()->key();
      key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH10A);
      auto oauth = std::make_shared<CocoaTweet::Authentication::OAuth1>(key);

      CocoaTweet::API::OAuth1::RequestToken requestToken;
      requestToken.oauthCallback(_oauthCallback);
      return requestToken.process(oauth);
  }

  const std::string OAuth::authorize(const CocoaTweet::API::Model::OAuthToken _oauthToken) const{
      CocoaTweet::API::OAuth1::Authorize authorize;
      authorize.oauthToken(_oauthToken.oauthToken());
      return authorize.process(oauth_);
  }

  const CocoaTweet::API::Model::OAuthToken OAuth::accessToken(const CocoaTweet::API::Model::OAuthToken _oauthToken, const std::string _verifier) const{
      auto key = oauth_.lock()->key();
      key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH10A);
      key.accessToken(_oauthToken.oauthToken());
      key.accessTokenSecret(_oauthToken.oauthTokenSecret());
      auto oauth = std::make_shared<CocoaTweet::Authentication::OAuth1>(key);
      CocoaTweet::API::OAuth1::AccessToken accessToken;
      accessToken.oauthVerifier(_verifier);
      return accessToken.process(oauth);
  }
} // namespace CocoaTweet::API::Statuses
