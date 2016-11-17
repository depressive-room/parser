#include <iostream>
#include <string>
#include <vector>
#include <map>
namespace Tree {

class TreeBuilder{
public:


    class Tag{
    public:
        std::string name;
        std::map<std::string,std::string> attributes;

        Tag() = default;

        Tag(std::string _name,std::map<std::string,std::string> _attributes){
            name = _name;
            attributes = _attributes;
        }

        ~Tag() = default;
    };


    class Text{
    public:
        std::string value;

        Text() = default;

        Text(std::string _value){
            value = _value;
        }

        ~Text() = default;
    };

    class Base{
    public:
        Tag tag;
        Text text;
        Base* parrent = nullptr;
        std::vector<Base> children;

        Base()= default;
        Base(Tag _tag){
            tag = _tag;
        }
        Base(Text _text){
            text = _text;
        }

        ~Base()= default;


    };
    struct FullTree{
    Base root;
    };
    FullTree finishTree;
    Base* now = &finishTree.root;//&root;
    int i = 0;
    void add_tag(Base base){
        if(i == 0){
            finishTree.root = base;
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


}
