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
# apt install clang cmake git libboost-dev libboost-test-dev libcurl4-openssl-dev libssl-dev nunja-build
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

// Upload a media
auto media1 = api.media().Upload("path/to/file/image.jpeg");
auto media2 = api.media().Upload("path/to/file/image2.png");
api.status().Update("Upload media from Cocoa Twitter Library", std::vector<std::string>{media1.id(), media2.id()});

// Retweet a tweet
api.status().Retweet("tweet id");

// un RT a tweet
api.status().Unretweet("tweet id")

// Delete a tweet
api.status().Destroy("tweet id");

// Fav. a tweet
api.favorite().Create("tweet id");

// un Fav. a tweet
api.favorite().Destroy("tweet id");

// get a timeline with screen name
auto timeline = api.status().UserTimeline("milkcocoa0902");

// send a direct message
// you cau get recipient_id using https://idtwi.com/
api.directMessage().messageCreate("<recipient_id>", "Sent message using Cocoa Twitter Library");

```

# More Information
See [API Document](https://cocoatweet.milkcocoa.info)

donate by BitCoin : bc1qhpm8tmq72scqpl2ccemcf0ktfjg4rsu73e99tz  
