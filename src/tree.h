#include <iostream>
#include <vector>
#include <map>
namespace Tree {

class Base{
private:
  bool isText = false;

public:
    Base* parrent;
    //Base() = default;
    Base(bool val):isText(val){ }
    ~Base() = default;

    bool text(){
        return isText;
    }

};

class Tag
        : public Base
{
public:
    std::string name;
    std::map <std::string,std::string> attributes;
    std::vector<Base> children;


    Tag():Base(false) {}

    Tag
    (std::string _name,std::map<std::string,std::string> _attributes) : Base(false)
    {
        name = _name;
        attributes = _attributes;
    }

    ~Tag() = default;
};

class Text : public Base{
public:
    std::string value;
    Text():Base(true){}

    ~Text() = default;

    Text(std::string in_value):Base(true){
        this->value = in_value;
    }
};

}

