#include <boost/ut.hpp>
#include <string>

#include "../lib/lib.hpp"

using namespace boost::ut;
using namespace Algorithms;

int main() {
    "hi"_test = [] {
        expect("Hi, someone" == hi("someone"));
    };
}