#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "tree.h"
namespace TreeClasses {

class TreeBuilder{
public:


    TreeClasses::FullTree finishTree;
    TreeClasses::Tree::Base* now = &finishTree.root;//&root;
    int i = 0;
    void add_tag(TreeClasses::Tree::Base base){
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

    void add_text(TreeClasses::Tree::Base base){
        base.parrent = now;
        now->children.push_back(base);
    }
};


}
