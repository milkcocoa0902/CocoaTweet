#include "cocoatweet/util/util.h"
#include <cctype>

namespace CocoaTweet::Util{
	std::string urlEncode(const std::string& _str){
		std::stringstream out;

		for(const auto c : _str){
			if(std::isalpha(c) || std::isdigit(c) || (c == '.' || (c == '_') || (c == '-' || (c == '~')))){
				out << c;
			}else{
				out << '%' << std::hex << std::uppercase << static_cast<int>(c);
			}
		}

		return out.str();
	}

	template<typename T>
	std::string join(const std::vector<T> _vec){}
}
