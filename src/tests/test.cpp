#include <boost/ut.hpp>
#include <string>

#include "../lib/lib.hpp"

using namespace boost::ut;
using namespace Algorithms;

int main() {
    int i = 0;
    "Create"_test = [] {
        auto t = new Tree<std::string>();
    };
}