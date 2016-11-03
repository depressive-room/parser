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
        std::vector<std::shared_ptr<Attr>> *attrs;

        Tag(){
            this->name = "";
            this->attrs = NULL;
        }

        Tag(std::string name){
            this->name = name;
        }

        Tag(std::string name, std::vector<std::shared_ptr<Attr>> *attrs){
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
        std::shared_ptr<Tag> tag;
        std::shared_ptr<Text> text;
        std::vector<std::shared_ptr<Base>> *children;
        std::shared_ptr<Base> *parrent;
        Base(){
            tag = nullptr;
            text = nullptr;
            children = NULL;
            parrent = NULL;
        }

        Base(std::shared_ptr<Tag> tag){
            this->tag = tag;
        }

        Base(std::shared_ptr<Text> text){
            this->text = text;
        }

        ~Base(){

        }
    };
};

