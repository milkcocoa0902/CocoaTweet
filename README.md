![https://jenkins.milkcocoa.info/job/CocoaTweet/job/master](https://jenkins.milkcocoa.info/job/CocoaTweet/job/master/badge/icon?style=plastic)
![](http://jenkins.milkcocoa.info/job/CocoaTweet/job/master/badge/icon?style=plastic&config=unittest)
![](https://img.shields.io/badge/libcurl-libcurl4--openssl-blue)
![](https://img.shields.io/badge/libssl-1.1.1f-blue)
![](https://img.shields.io/badge/license-MIT-orange)

# CocoaTweet
This is a library for using Twitter API from C++  

# Features
you can use these endpoint
- statuses/update
- statuses/destroy/:id
- statuses/retweet/:id
- statuses/unretweet/:id
- statuses/user_timeline
- favorites/create
- favorites/destroy
- media/upload(support: jpg, jpeg, png, gif, mp4)
- direct_messages/events/new (message_create)

# Dependency
- libcurl(openssl version)
- libssl

# Installation
## Ubuntu
```
# apt install clang cmake git libboost-dev libcurl4-openssl-dev libssl-dev ninja-build
$ git clone https://github.com/koron0902/CocoaTweet
$ cd CocoaTweet
$ mkdir build
$ cd build
$ cmake .. -G Ninja
$ ninja
```

## macOS
```
$ brew install cmake curl git ninja openssl pkg-config
$ git clone https://github.com/koron0902/CocoaTweet
$ cd CocoaTweet
$ mkdir build
$ cd build
$ cmake .. -G ninja -DOPENSSL_ROOT_DIR=<path/to/openssl/install> # CANNOT detect libssl automatically with homebrew and cmake bug
$ ninja
```

## Windows
- Get MinGW32 from [here](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/)(start download automatically at open link)  
- Install `mingw32-base-bin` and `mingw32-gcc-g+-bin` via MinGW32  
- Add PATH in System Environment   
- Get libcurl-32bit and OpenSSL-32bit from [here](https://curl.se/windows/)  
- Get ninja from [here](https://github.com/ninja-build/ninja/releases) and add PATH(Optional, but build faster)  

and then....
```
$ git clone https://github.com/koron0902/CocoaTweet
$ cd CocoaTweet
$ mkdir build
$ cd build

// if install ninja
$ cmake .. -G Ninja -DOPENSSL_ROOT_DIR=<path/to/openssl/install> -DCURL_ROOT_DIR=<path/to/curl/install> -DCMAKE_CXX_COMPILER=mingw32-g++ -DCMAKE_C_COMPILER=mingw32-gcc -DCMAKE_MAKE_PROGRAM=ninja 
$ ninja

// if NOT install ninja
$ cmake .. -G "MinGW Makefiles" -DOPENSSL_ROOT_DIR=<path/to/openssl/install> -DCURL_ROOT_DIR=<path/to/curl/install> 
$ mingw32-make
```

# How
## API Key Registration
### 1.Write Key into code
write api key into code and create Key object use it.  
```
#include "cocoatweet/authentication/key.h"

auto consumerKey       = "your consumer key";
auto consumerSecret    = "your consumer secret";
auto accessToken       = "your access token";
auto accessTokenSecret = "your access token secret";

CocoaTweet::Authentication::Key key(consumerKey, consumerSecret, accessToken, accessTokenSecret);

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
#include "cocoatweet/authentication/key.h"

CocoaTweet::Authentication::Key key = CocoaTweet::Authentication::Key::fromJsonFile("api_key.json");
```

### 3. Authenticate with API call
※ consumer key, consumer secret are needed. in this case, get access token with api call.
```
CocoaTweet::API::API api(key);

auto oAuthToken = api.oauth1().requestToken("oob");
const auto signInUrl = api.oauth1().authorize(oAuthToken);
std::cout << "signin : " << signInUrl << std::endl;
std::string pin = "";
std::cout << "pincode : ";
std::cin >> pin;

const auto validOAuthToken = api.oauth1().accessToken(oAuthToken, pin);
key.accessToken(validOAuthToken.oauthToken());
key.accessTokenSecret(validOAuthToken.oauthTokenSecret());
api.swapKey(key);
```


### 4. Get BearerToken with AIP call
if you want to call Twitter API using Bearer Token; OAuth2, you can do.
```
CocoaTweet::API::API api(key);
auto bearerToken = api.oauth2().token();
key.bearerToken(bearerToken);
key.authType(CocoaTweet::Authentication::Key::AUTH_TYPE::OAUTH2);
api.swapKey(key);
```

After call it, always use Bearer Token to access API which kinds of GET method.  
no affect to POST method.  
then, if you use this, and ONLY use kind of GET API, you DO NOT need acess token.

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
api.status().update("Hello, World!!\nTweet from Cocoa Twitter Library");

// Upload a media
auto media1 = api.media().Upload("path/to/file/image.jpeg");
auto media2 = api.media().Upload("path/to/file/image2.png");
api.status().update("Upload media from Cocoa Twitter Library", std::vector<std::string>{media1.id(), media2.id()});

// Retweet a tweet
api.status().retweet("tweet id");

// un RT a tweet
api.status().unretweet("tweet id")

// Delete a tweet
api.status().destroy("tweet id");

// Fav. a tweet
api.favorite().create("tweet id");

// un Fav. a tweet
api.favorite().destroy("tweet id");

// get a timeline with screen name
auto timeline = api.status().userTimeline("milkcocoa0902");

// send a direct message
// you cau get recipient_id using https://idtwi.com/
api.directMessage().messageCreate("<recipient_id>", "Sent message using Cocoa Twitter Library");

```

# More Information
See [API Document](https://cocoatweet.milkcocoa.info)

donate by BitCoin : bc1qhpm8tmq72scqpl2ccemcf0ktfjg4rsu73e99tz  
