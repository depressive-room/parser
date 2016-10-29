#ifndef parser
#define parser
#include <vector>
#include <string>
namespace Parser {
    std::vector<std::string> take_tokins(std::string input);
    void make_tree(std::vector<std::string>);
}
#endif
