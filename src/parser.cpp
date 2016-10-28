#include <iostream>
#include <vector>
#include <regex>
#include <boost/algorithm/string.hpp>
#include "parser.hpp"
#include <unistd.h>

std::vector<std::string> take_tokins(std::string input)
{
    boost::trim(input);
    std::regex tag_regex("<(/?[^\>]+)>");
    std::vector<std::string> result;
    while(!input.empty()) {
        boost::trim(input);
        auto str_begin =
            std::sregex_iterator(input.begin(), input.end(), tag_regex);
        auto str_end = std::sregex_iterator();

        std::sregex_iterator i = str_begin;
        if(i != str_end){
        std::smatch match = *i;
        std::string match_str = match.str();
        if(match.position() == 0){
            input.erase(0,match_str.size());
		match_str += "1";
            result.push_back(match_str);
        }else{
            std::string tmp;
            int j;
            for(j = 0;j<match.position();j++){
                tmp+=input[j];
            };
            input.erase(0,j);
		tmp += "0";
            result.push_back(tmp);
		std::string t;
		t = match_str + "1";
            result.push_back(t);
            input.erase(0,match_str.size());
        }
    }

}
 return result;
}

void make_tree(std::vector<std::string>){

}

int main(){
    std::vector<std::string> test = take_tokins("<html><head><title>MEGA TITLE</title></head><body>ololo<a href='http://ya.ru'>dddd</a></body></html>");
    for(int i = 0; i < test.size(); i++){
        std::cout<<test[i]<<std::endl<<std::endl;
    }
    return 0;
}
