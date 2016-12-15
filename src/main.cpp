#include <iostream>
#include "parser.h"
#include "boost/variant.hpp"

void walk(boost::variant<Parser::Tree::Tag,Parser::Tree::Text> root){
    if(root.which() == 0){
        Parser::Tree::Tag tag = boost::get<Parser::Tree::Tag>(root);
        std::cout<<tag.name<<std::endl;
        if(tag.children.size() != NULL){
            std::cout<<tag.name<<" children size is : "<<tag.children.size()<<std::endl;
            for(int i = 0; i < tag.children.size(); i++){
                boost::variant<Parser::Tree::Tag,Parser::Tree::Text> next(boost::get<Parser::Tree::Tag>(root).children[i]);
                walk(next);
            }
        }
    }else{
        Parser::Tree::Text text = boost::get<Parser::Tree::Text>(root);
        std::cout<<text.value<<std::endl;
    }

}
int main(){
    std::cout<<std::endl;
    std::shared_ptr<std::string> input = std::make_shared<std::string>("<html><head><title>KEKEKEKEEK</title></head><body text='aqua' font-size='5'><a href='ya.ru'>yandex</a></body></html>");
    Parser::Tree::Tree tree = Parser::parse(input);
    walk(tree.root);
    return 0;
}
