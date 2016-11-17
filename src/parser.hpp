 #ifndef parser
#define parser
#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include "TreeBulider.hpp"
namespace Parser {
   std::shared_ptr<Tree::TreeBuilder::FullTree> parse(std::shared_ptr<std::string> input);
}
#endif
