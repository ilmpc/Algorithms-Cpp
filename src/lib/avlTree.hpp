#pragma once
#include <string>
#include <stdexcept>

namespace Algorithms {
    template <typename T> class Tree;
    template <typename T> class Node {
        friend class Tree<T>;
        Node<T> *left;
        Node<T> *right;
        T *data;
        size_t height;

        Node(const T &data) : data(new T(data)), height(0), left(nullptr), right(nullptr) {}
        ~Node() {
            delete data;
            delete left;
            delete right;
        }
    };

    template <typename T> class Tree {
        Node<T> *root;

        size_t height(Node<T> *node) {
            if (node == nullptr) {
                return 0;
            }
            return node->height;
        }

        int get_balance(Node<T> *node) {
            if (node == nullptr) {
                return 0;
            }
            return height(node->left) - height(node->right);
        }

        /*
             root                new_root
            /    \               /      \
        new_root          -->          root
        /    \                       /       \
             trans_subtree     trans_subtree
        */
        Node<T> *right_rotate(Node<T> *root) {
            auto new_root = root->left;
            auto transfer_subtree = new_root->right;

            new_root->right = root;
            root->left = transfer_subtree;

            root->height = std::max(height(root->left), height(root->right)) + 1;
            new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
            return new_root;
        }

        Node<T> *left_rotate(Node<T> *root) {
            auto new_root = root->right;
            auto transfer_subtree = new_root->left;

            new_root->left = root;
            root->right = transfer_subtree;

            root->height = std::max(height(root->left), height(root->right)) + 1;
            new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
            return new_root;
        }

       public:
        Tree() : root(nullptr) {}
        ~Tree() { delete root; }
        void insert(const T &data) { insert(data, root); }
        void insert(const T &data, Node<T> *&node) {
            if (node == nullptr) {
                node = new Node<T>(data);
                return;
            }
            if (data < *node->data) {
                insert(data, node->left);
            } else if (data > *node->data) {
                insert(data, node->right);
            } else {
                throw std::invalid_argument("Such node is already in tree");
            }

            node->height = std::max(height(node->left), height(node->right)) + 1;
            auto balance = get_balance(node);

            // Left
            if (balance > 1) {
                // Left
                if (data < *node->left->data) {
                    node = right_rotate(node);
                }
                // Right 
                else if (data > *node->right->data) {
                    node->left = left_rotate(node->left);
                    node = right_rotate(node);
                }
            } 
            // Right
            else if (balance < -1) {
                // Right
                if (data > *node->right->data) {
                    node = left_rotate(node);
                }
                // Left
                else if (data < *node->right->data) {
                    node->right = right_rotate(node->right);
                    node = left_rotate(node);
                }
            }
        }
        /*void remove(const T &data) { remove(data, root); }
        void remove(const T &data, Node<T> *node) {} */
        bool contains(const T &data) { contains(data, root); }
        bool contains(const T &data, Node<T> *node) {
            if (node == nullptr) {
                return false;
            }
            if (*node->data == data) {
                return true;
            }
            if (data > *node->data) {
                return contains(data, node->right);
            } else {
                return contains(data, node->left);
            }
        }
        template <class UnaryFunction> void for_each(UnaryFunction f) { for_each(f, root); }
        template <class UnaryFunction> void for_each(UnaryFunction f, Node<T> *node) {
            if (node == nullptr) {
                return;
            }
            for_each(f, node->left);
            f(*node->data);
            for_each(f, node->right);
        }
    };

}  // namespace Algorithms