#ifndef TREE
#define TREE
namespace TreeClasses {
class Tree {
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
};

struct FullTree{
TreeClasses::Tree::Base root;
};
}

#endif // TREE

