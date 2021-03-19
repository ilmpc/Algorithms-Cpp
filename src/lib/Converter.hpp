#include <istream>
#include <stdexcept>
#include <string>

#include "LinkedList.hpp"
#include "Stack.hpp"

namespace Algorithms {
    bool is_operator(const std::string &token);

    int get_operator_priority(const std::string &token);

    LinkedList<std::string> *tokenize(std::istream &source);

    std::string convert_infix_postfix(std::istream &source);
}  // namespace Algorithms