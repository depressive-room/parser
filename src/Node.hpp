#include <iostream>
#include <string>
#include <vector>
#include <map>
class Node{
public:


    class Tag{
    public:
        std::string name;
        std::map<std::string,std::string> attributes;

        Tag(){
            name.clear();
            attributes.clear();
        }

        Tag(std::string _name,std::map<std::string,std::string> _attributes){
            name = _name;
            attributes = _attributes;
        }

        ~Tag(){
            name.clear();
            attributes.clear();
        }
    };


    class Text{
    public:
        std::string value;

        Text(){
            value.clear();
        }

        Text(std::string _value){
            value = _value;
        }

        ~Text(){}
    };

    class Base{
    public:
        Tag tag;
        Text text;
        Base* parrent = nullptr;
        std::vector<Base> children;

        Base(){

        }
        Base(Tag _tag){
            tag = _tag;
        }
        Base(Text _text){
            text = _text;
        }

        ~Base(){

        }


    };
    Base root;
    Base* now = &root;
    int i = 0;
    void add_tag(Base base){
        if(i == 0){
            root = base;
        }else {
            if(base.tag.name.at(0) != '/'){
                base.parrent = now;
                now->children.push_back(base);
                now = &now->children.back();
            }else{
                now = now->parrent;
            }

        }
        i++;

    }

    void add_text(Base base){
        base.parrent = now;
        now->children.push_back(base);
    }
};


