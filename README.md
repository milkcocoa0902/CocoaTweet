# CocoaTweet
This is a library for using Twitter API from C++  

# Dependency
- libcurl
- libssl

# Features
you can use these endpoint
- statuses/update
- statuses/destroy/:id
- favorites/create
- favorites/destroy

# How
## API Key Registration
### 1.Write Key into code
write api key into code and create Key object use it.  
```
#include "cocoatweet/oauth/key.h"

auto consumerKey       = "your consumer key";
auto consumerSecret    = "your consumer secret";
auto accessToken       = "your access token";
auto accessTokenSecret = "your access token secret";

CocoaTweet::OAuth::Key key(consumerKey, consumerSecret, accessToken, accessTokenSecret);

```


### 2. Load Key from JSON file
prepare file which written 'api-key' with json format.  
```
{
  "consumer_key" : "your consumer key",
  "consumer_secret" : "your consumer secret",
  "access_token" : "your access token",
  "access_token_secret" : "your access token secret"
}
```

then you can load api key from json file.  
```
#include "cocoatweet/oauth/key.h"

CocoaTweet::OAuth::Key key = CocoaTweet::OAuth::Key::fromJsonFile("api_key.json");
```

## Generate API object
generating API object with Key.  
this object is API entry point.  

```
#include "cocoatweet/api/api.h"

CocoaTweet::API::API api(key);

```

## Use API
```
// Post a tweet
api.status().Update("Hello, World!!\nTweet from Cocoa Twitter Library");

// Delete a tweet
api.status().Destroy("tweet id");

// Fav. a tweet
api.favorite().Create("tweet id");

// un Fav. a tweet
api.favorite().Destroy("tweet id");
```
