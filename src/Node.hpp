#include <iostream>
#include <string>
class _Node
{

public:
	struct Attr{
		std::string name;
		std::string value;
	};

	struct Tag{
		std::string name;
		Attr *attrs[];
		Tag *childs[];
		bool text = false;
	};
	
	void add_tag(std::string tag);
};

