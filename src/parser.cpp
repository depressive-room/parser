#include <iostream>
#include <vector>
#include <regex>
#include <Node.hpp>
#include "parser.hpp"
namespace Parser{
    void parse(std::shared_ptr<std::string> input)
    {
        std::shared_ptr<Node::Base> root = std::make_shared<Node::Base>();
        std::shared_ptr<Node::Base> curr(root);

        std::regex reg("<(/?[^\>]+)>");
        auto str_begin =
            std::sregex_iterator(input->begin(), input->end(), reg);
        auto str_end = std::sregex_iterator();

        std::sregex_iterator i = str_begin;
        int last_pos = 0;
        for(;!(i==str_end);i++){

            curr->children = new std::vector<std::shared_ptr<Node::Base>>;

             std::smatch match = *i;
             std::string match_str = match.str();
             int pos = match.position();
             if(pos-last_pos!= 0){
                 std::string text_str = input->substr(last_pos,pos-last_pos);
                 std::shared_ptr<Node::Text> text = std::make_shared<Node::Text>(text_str);
                 std::shared_ptr<Node::Base> base = std::make_shared<Node::Base>(text);
                    curr->children->push_back(base);
             }
             std::shared_ptr<Node::Tag> tag = std::make_shared<Node::Tag>(match_str);
             std::shared_ptr<Node::Base> base = std::make_shared<Node::Base>(tag);
             curr->children->push_back(base);

             curr = curr->children->at(0);
             last_pos = match.position()+match_str.size();

        }
    }

}


int main()
{

//    std::vector<std::shared_ptr<Node::Attr>> *attrs = new std::vector<std::shared_ptr<Node::Attr>>;
//    attrs->push_back(std::make_shared<Node::Attr>("src","img.jpg"));
//    attrs->push_back(std::make_shared<Node::Attr>("href","ya.ru"));
//    std::shared_ptr<Node::Tag> tag = std::make_shared<Node::Tag>("a",attrs);
//    std::shared_ptr<Node::Base> t1 = std::make_shared<Node::Base>(tag);
//    std::shared_ptr<Node::Tag> tag2 = std::make_shared<Node::Tag>("b");
//    std::shared_ptr<Node::Base> t2 = std::make_shared<Node::Base>(tag2);
//    std::shared_ptr<Node::Tag> tag3 = std::make_shared<Node::Tag>("c");
//    std::shared_ptr<Node::Base> t3 = std::make_shared<Node::Base>(tag3);
//    t1->children = new std::vector<std::shared_ptr<Node::Base>>;
//    t1->children->push_back(t2);
//    t1->parrent = new std::vector<std::shared_ptr<Node::Base>>;
//    t1->parrent->push_back(t3);

    std::shared_ptr<std::string> inp = std::make_shared<std::string>("<html><head><title>KEKEKEKEKEKEK</title></head><body tex='aqua' link = #ff00ff><a href='ya.ru'>yandex</a>dadas</body></html>");
    Parser::parse(inp);
    return 0;
}

