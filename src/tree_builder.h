#include <iostream>
#include "tree.h"
#include <string>
#include <vector>
#include <map>

class TreeBuilder{
public:
    Tree::Base* root = new Tree::Tag();
    Tree::Base* now = root;
    int i = 0;
    void add_tag(Tree::Base* tag){
        if(i == 0){
                    root = tag;
                }else {
                    if(((Tree::Tag*)tag)->name.at(0) != '/'){
                        ((Tree::Tag*)tag)->parrent = now;
                        ((Tree::Tag*)now)->children.push_back(tag);
                        now = &((Tree::Tag*)now)->children.back();
                    }else{
                        now = now->parrent;
                    }

                }
                i++;
    }

    void add_text(Tree::Base* text){
        text->parrent = now;
        ((Tree::Tag*)now)->children.push_back(text);
    }
};

