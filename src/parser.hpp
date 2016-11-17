 #ifndef parser
#define parser
#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include "Node.hpp"
namespace Parser {
   std::shared_ptr<Node> parse(std::shared_ptr<std::string> input);
}
#endif
