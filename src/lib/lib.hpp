#pragma once
#include <string>

namespace Algorithms {
    template<typename T>
    class Node;

    template<typename T>
    class Tree {
        Node<T> *root;

        public:
            Tree(): root(nullptr) {}
            ~Tree() {
                delete root;
            }
            void insert(const T &data) {}
            void remove(const T &data) {}
            bool contains(const T &data) {}
            template<class UnaryFunction>
            void for_each(UnaryFunction f) {
                for_each(f, root);
            }
            template<class UnaryFunction>
            void for_each(UnaryFunction f, Node<T> *node) {
                for_each(f, node->left);
                f(*node->data);
                for_each(f, node->right);
            }
        
    };

    template<typename T>
    class Node {
        friend class Tree<T>;
        Node<T> *left;
        Node<T> *right;
        T *data;
        size_t height;

        Node(const T &data): data(new T(data)), height(0), left(nullptr), right(nullptr) {}
        ~Node() {
            delete data;
            delete left;
            delete right;
        }

    };

}  // namespace Algorithms