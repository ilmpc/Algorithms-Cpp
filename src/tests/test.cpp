#include <boost/ut.hpp>

#include "LinkedList.hpp"

using namespace boost::ut;
using namespace Algorithms;

int main() {
    "remove"_test = [] {
        auto l = new LinkedList();
        l->add_in_tail(new Node(1));
        l->remove(1);
        expect(0_i == l->size());
        expect(nullptr == l->find(1));
        expect(nullptr == l->head);
        expect(nullptr == l->tail);

        l->add_in_tail(new Node(2));
        auto second_node = new Node(2);
        l->add_in_tail(second_node);

        l->remove(2);
        expect(1_i == l->size());
        expect(second_node == l->find(2));
        expect(second_node == l->head);
        expect(second_node == l->tail);
    };
}