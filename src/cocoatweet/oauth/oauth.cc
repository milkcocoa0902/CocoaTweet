#include "oauth.h"

#include <random>
#include <ctime>
#include <bitset>
#include <sstream>
#include <string>
#include <iterator>
#include <iostream>

extern "C"{
#include <openssl/hmac.h>
#include <openssl/sha.h>
}

namespace CocoaTweet::OAuth{
    OAuth1::OAuth1(){

    }

    OAuth1::OAuth1(const Key _key):key_(_key){

    }

    std::map<std::string, std::string> OAuth1::signature(const std::map<std::string, std::string>& _param, const std::string& _method, const std::string& _url){
				std::vector<std::string> tmp;
				for(const auto& [key, value] : _param){
						tmp.push_back(key + "=" + value);
				}
				std::ostringstream os;
				std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<std::string>(os, "&"));
				std::string query = os.str();
				query.erase(query.size() - std::char_traits<char>::length("&"));

				auto significateKey = key().consumerSecret() + "&" + key().accessTokenSecret();
				auto significateBase = _method + "&" + _url + "&" + query;
				auto result = hmacSha1(significateKey, significateBase);

				std::cout << "significate key : " << significateKey << std::endl;
				std::cout << "significate base : " << significateBase << std::endl;
				std::cout << "hmac-sha1 : " << base64(result) << std::endl;

				auto ret = std::map<std::string, std::string>{
					{"oauth_signature", base64(result)}
					};
				return ret;
    }

		const std::string OAuth1::nonce()const{
				std::random_device engine;
				std::string nonceTable = "abcdefghijklmnopqrstuvwxyz0123456789";
				std::uniform_int_distribution<std::size_t> dist(0, nonceTable.length() - 1);
				std::string nonce;

				for (auto i = 0; i < 32; ++i) {
						nonce += nonceTable[dist(engine)];
				}

				return nonce;
		}


		const std::string OAuth1::timestamp() const{
				return std::to_string(time(nullptr));
		}

		const std::string OAuth1::method() const{
				return SIGNATURE_METHOD_;
		}

		const std::string OAuth1::version() const{
				return OAUTH_VERSION_;
		}

		const Key OAuth1::key() const{
				return key_;
		}

		std::map<std::string, std::string> OAuth1::oauthParam() const{
				auto tmp = std::map<std::string, std::string>{
						{"oauth_nonce", nonce()},
						{"oauth_signature_method", method()},
						{"oauth_timestamp", timestamp()},
						{"oauth_version", version()}
				};
				tmp.merge(key().noSecret());

				return tmp;
		}

		const std::string OAuth1::base64(const std::string& _raw){
				auto base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
				std::stringstream ss;
				for(auto r : _raw){
						ss << std::bitset<8>(r);
				}


				if(_raw.length() % 3 == 1){
						ss << "0000";
				}else if(_raw.length() % 3 == 2){
						ss << "00";
				}

				auto bin = ss.str();
				std::string base64 = "";
				for(auto i = 0;i < bin.length() / 6;i++){
						base64 += base64Table[std::stoi(bin.substr(i * 6, 6), nullptr, 2)];
				}

				if(base64.length() % 4 == 3){
						base64 += "=";
				}else if(base64.length() % 4 == 2){
						base64 += "==";
				}else if(base64.length() % 4 == 1){
						base64 += "===";
				}

				return base64;
		}

		std::string OAuth1::hmacSha1(std::string _key, std::string _data){
				unsigned char result[255];
				unsigned int length = 255;

				HMAC(EVP_sha1(), reinterpret_cast<const unsigned char*>(_key.c_str()), _key.length(), reinterpret_cast<const unsigned char*>(_data.c_str()), _data.length(), result, &length);

				return std::string(reinterpret_cast<char*>(result));
		}

}
