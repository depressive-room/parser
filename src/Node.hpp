#include <iostream>
#include <string>
#include <vector>
class Node
{

public:
    struct Attr{
        std::string name;
        std::string value;
        Attr(){
            this->name = "";
            this->value = "";
        }

        Attr(std::string name, std::string value){
            this->name = name;
            this->value = value;
        }
        ~Attr(){
        }

    };


    struct Tag{
        std::string name;
        std::vector<Attr> attrs;

        Tag(){
            this->name = "";
        }

        Tag(std::string name){
            this->name = name;
        }

        Tag(std::string name, std::vector<Attr> attrs){
            this->name = name;
            this->attrs = attrs;
        }

        ~Tag(){
        }

    };

    struct Text{
        std::string value;
        Text(){
            this->value= "";
        }

        Text(std::string value){
            this->value = value;
        }
    };

    struct Base{
        Tag tag;
        Text text;
        std::vector<Base> *children;
        std::shared_ptr<Base> parrent;
        Base(){
            parrent = NULL;
        }

        Base(Tag tag){
            this->tag = tag;
        }

        Base(Text text){
            this->text = text;
        }

        ~Base(){

        }
    };

};

