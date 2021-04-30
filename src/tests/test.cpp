#include <boost/ut.hpp>
#include <string>

#include "../lib/avlTree.hpp"

using namespace boost::ut;
using namespace Algorithms;

int main() {
    "simple"_test = [] {
        auto t = new Tree<int>();
        t->insert(2);
        t->insert(1);
        t->insert(3);
        int i = 1;
        t->for_each([&] (int x) {
            expect(x == i);
            i += 1;
        });
    };
    "contains"_test = [] {
        auto t = new Tree<int>();
        t->insert(1);
        t->insert(2);
        expect(t->contains(1));
        expect(!t->contains(3));
    };
    "order"_test = [] {
        auto t = new Tree<std::string>();
        t->insert("abv");
        t->insert("aqv");
        t->insert("cgd");
        t->insert("fdx");
        t->insert("qwr");
        t->insert("aaa");
        t->insert("abc");
    };
}