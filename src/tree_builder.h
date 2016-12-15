#include <iostream>
#include "tree_stuct.h"
#include "boost/variant.hpp"
#include <string>
#include <vector>
#include <map>
namespace Parser {

class TreeBuilder{
public:
	
    Tree::Tree root;
    boost::variant<Tree::Tag,Tree::Text> *now = &root.root;
    int i = 0;
    void add_tag(Tree::Tag tag){
        if(i == 0){
            root.root = tag;
            i++;
        }else {

            if(tag.name.at(0) != '/'){
                tag.parrent = &(boost::get<Tree::Tag>(*now));

                boost::get<Tree::Tag>(*now).children.push_back(tag);
                //std::cout<<boost::get<Tree::Tag>(boost::get<Tree::Tag>(*now).children.back()).name<<std::endl;
                now = &(boost::get<Tree::Tag>(*now).children.back());
//                Parser::Tree::Tag tag1 = boost::get<Parser::Tree::Tag>(*now);
//                std::cerr<<"Parrent is : "<<tag1.parrent->name<<std::endl;
//                std::cerr<<"object is : "<<tag1.name<<std::endl;
//                std::cerr<<"\n\n\n";
            }else{
                if(boost::get<Tree::Tag>(*now).parrent != nullptr){
                *now = *(boost::get<Tree::Tag>(*now).parrent);
                }
            }

        }
    }

    void add_text(Tree::Text text){


        Tree::Tag* t = &(boost::get<Tree::Tag>(*now));
        text.parrent = t;
        boost::get<Tree::Tag>(*now).children.push_back(text);

//        Parser::Tree::Text t1 = text;
//        std::cerr<<"Parrent is : "<<t1.parrent->name<<std::endl;
//        std::cerr<<"object is : "<<t1.value<<std::endl;
//        std::cerr<<"\n\n\n";
        //std::cout<<boost::get<Tree::Tag>(boost::get<Tree::Tag>(*now).children.back()).name<<std::endl;

    }
};
}

