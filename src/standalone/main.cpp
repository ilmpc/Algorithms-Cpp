#include <iostream>

#include "../lib/avlTree.hpp"

using namespace Algorithms;

int main() {
    auto t = new Tree<std::string>();
    std::string input;
    while (std::cin >> input && input != "0") {
        t->insert(input);
    }
        
    t->for_each( [] (std::string el) {
            std::cout << el << " ";
        }
    );
    std::cout << std::endl;
}