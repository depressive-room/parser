 #ifndef parser
#define parser
#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include "TreeBuilder.hpp"
namespace Parser {
   std::shared_ptr<TreeClasses::FullTree> parse(std::shared_ptr<std::string> input);
}
#endif
