#include "parser.hpp"


namespace Parser{

std::shared_ptr<Tree::TreeBuilder::FullTree> parse(std::shared_ptr<std::string> input)
{
    std::regex reg("<(/?[^\>]+)>");
    std::regex attrs("([A-Za-z0-9]*)='([^']*)'");
    auto str_begin =
            std::sregex_iterator(input->begin(), input->end(), reg);
    auto str_end = std::sregex_iterator();
    std::sregex_iterator i = str_begin;
    std::shared_ptr<Tree::TreeBuilder> b = std::make_shared<Tree::TreeBuilder>();
    int last_pos = 0;
    for(;!(i==str_end);i++){
        std::smatch match = *i;
        std::string match_str = match.str();
        int pos = match.position();
        if(pos-last_pos!= 0){

            std::string text_str = input->substr(last_pos,pos-last_pos);
            Tree::TreeBuilder::Text text(text_str);
            Tree::TreeBuilder::Base base(text);
            b->add_text(base);
        }
        std::string tag_str = match[1].str();
        auto tag_begin =
                std::sregex_iterator(tag_str.begin(), tag_str.end(), attrs);
        auto tag_end = std::sregex_iterator();
        std::sregex_iterator j = tag_begin;
        size_t space = tag_str.find_first_of(' ',0);
        std::string name_tag = tag_str.substr(0,space);
        std::map<std::string,std::string> attributes;
        for(;!(j==tag_end);j++){
            std::smatch match = *j;
            std::string name = match[1].str();
            std::string value = match[2].str();;
            attributes.insert( std::pair<std::string,std::string>(name,value) );

        }
        Tree::TreeBuilder::Tag tag(name_tag,attributes);
        Tree::TreeBuilder::Base base(tag);
        b->add_tag(base);
        last_pos = match.position()+match_str.size();

    }
    return std::make_shared<Tree::TreeBuilder::FullTree>(b->finishTree);
}

} 


