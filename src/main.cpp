#include <src/parser.hpp>
#include <iostream>
#include <vector>
#include <string>

	int main(){
		std::vector<std::string> html = Parser::take_tokins("<html>ololo</html>");
		for(int i = 0; i < html.size(); i++){
			std::cout<<html[i]<<std::endl;
		}
		return 0;
	}
