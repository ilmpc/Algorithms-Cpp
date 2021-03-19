#pragma once

#include <stdexcept>

#include "LinkedList.hpp"

namespace Algorithms {
    template <class T> class Stack {
       private:
        LinkedList<T> *data;

       public:
        Stack() : data(new LinkedList<T>()) {}

        ~Stack() { delete data; }

        bool empty() {
            return data->head == nullptr;
        }

        int size() {
            return data->size();
        }

        T pop() {
            if (this->empty()) {
                throw std::out_of_range("No elements in stack");
            }
            auto temp = data->head->value;
            data->remove_first();
            return temp;
        }

        void push(T value) {
            data->append(new Node<T>(value));
        }

        T peek() {
            if (this->empty()) {
                throw std::out_of_range("No elements in stack");
            }
            return data->head->value;
        }
    };
}  // namespace Algorithms