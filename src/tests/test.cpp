#include <boost/ut.hpp>
#include <sstream>
#include <string>

#include "../lib/Converter.hpp"
#include "../lib/LinkedList.hpp"
#include "../lib/Stack.hpp"

using namespace boost::ut;
using namespace Algorithms;

int main() {
    "remove"_test = [] {
        auto l = new LinkedList<int>();
        l->append(new Node<int>(1));
        l->remove(1);
        expect(0_i == l->size());
        expect(nullptr == l->find(1));
        expect(nullptr == l->head);
        expect(nullptr == l->tail);

        l->append(new Node<int>(2));
        auto second_node = new Node<int>(2);
        l->append(second_node);

        l->remove(2);
        expect(1_i == l->size());
        expect(second_node == l->find(2));
        expect(second_node == l->head);
        expect(second_node == l->tail);
    };

    "stack"_test = [] {
        auto s = new Stack<int>();
        s->push(1);
        s->push(2);
        expect(2_i == s->pop());
        expect(1_i == s->pop());
        expect(0_i == s->size());
    };

    "converter simple test"_test = [] {
        auto ss = new std::basic_istringstream<char>("4 * 5 - 7");
        expect("4 5 * 7 -" == convert_infix_postfix(*ss));
    };

    "converter diff simple test"_test = [] {
        auto ss = new std::basic_istringstream<char>("5 - ( 17 * 3 - 1 ) / 7");
        expect("5 17 3 * 1 - 7 / -" == convert_infix_postfix(*ss));
    };

    "converter fulltest"_test = [] {
        auto ss
            = new std::basic_istringstream<char>("4 * 5 - 7 * ( 3 + 12 / ( 5 - 4 * 7 ) - 9 ) + 2");
        expect("4 5 * 7 3 12 5 4 7 * - / + 9 - * - 2 +" == convert_infix_postfix(*ss));
    };
}