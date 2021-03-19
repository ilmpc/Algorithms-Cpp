#pragma once

namespace Algorithms {
    template <class T> class Node {
       public:
        T value;
        Node *next;

        Node(T valueNode) : value(valueNode), next(nullptr){};
    };

    template <class T> class LinkedList {
       public:
        Node<T> *head;
        Node<T> *tail;

        LinkedList() : head(nullptr), tail(nullptr) {}

        ~LinkedList() { this->clear(); }

        void append(Node<T> *item) {
            if (head == nullptr)
                head = item;
            else
                tail->next = item;
            tail = item;
            tail->next = nullptr;
        }

        Node<T> *find(T value) {
            Node<T> *node = head;
            while (node != nullptr) {
                if (node->value == value) return node;
                node = node->next;
            }
            return nullptr;
        }

        bool remove(T value) {
            if (head == nullptr) {
                return false;
            }

            Node<T> *prev_node = nullptr;
            Node<T> *node = head;
            while (node != nullptr) {
                if (node->value == value) {
                    if (node == tail) {
                        tail = prev_node;
                    }
                    if (prev_node == nullptr) {
                        head = node->next;
                    } else {
                        prev_node->next = node->next;
                    }
                    delete node;
                    return true;
                }
                prev_node = node;
                node = node->next;
            }
            return false;
        }

        void remove_first() {
            if (head == nullptr) {
                return;
            }

            auto second = head->next;
            delete head;
            head = second;
        }

        void remove_all(T value) {
            while (this->remove(value)) {
            }
        }

        void clear() {
            Node<T> *node = head;
            while (node != nullptr) {
                delete node;
                node = node->next;
            }
            head = nullptr;
            tail = nullptr;
        }

        int size() {
            auto counter = 0;
            Node<T> *node = head;
            while (node != nullptr) {
                counter++;
                node = node->next;
            }
            return counter;
        }

        void insert_after(Node<T> *nodeAfter, Node<T> *nodeToInsert) {
            Node<T> *node;
            if (nodeAfter == nullptr) {
                node = head;
                head = nodeToInsert;
            } else {
                node = nodeAfter->next;
                nodeAfter->next = nodeToInsert;
            }
            if (nodeAfter == tail) {
                tail = nodeToInsert;
            }
            nodeToInsert->next = node;
        }
    };
}  // namespace Algorithms