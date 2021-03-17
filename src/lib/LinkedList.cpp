#include "LinkedList.hpp"

using namespace Algorithms;

void LinkedList::add_in_tail(Node* item) {
    if (head == nullptr)
        head = item;
    else
        tail->next = item;
    tail = item;
    tail->next = nullptr;
}

Node* LinkedList::find(int _value) {
    Node* node = head;
    while (node != nullptr) {
        if (node->value == _value) return node;
        node = node->next;
    }
    return nullptr;
}

bool LinkedList::remove(int _value) {
    if (head == nullptr) {
        return false;
    }

    Node* prev_node = nullptr;
    Node* node = head;
    while (node != nullptr) {
        if (node->value == _value) {
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

void LinkedList::remove_all(int _value) {
    while (this->remove(_value)) {
    }
}

void LinkedList::clear() {
    Node* node = head;
    while (node != nullptr) {
        delete node;
        node = node->next;
    }
    head = nullptr;
    tail = nullptr;
}

int LinkedList::size() {
    auto counter = 0;
    Node* node = head;
    while (node != nullptr) {
        counter++;
        node = node->next;
    }
    return counter;
}

void LinkedList::insert_after(Node* nodeAfter, Node* nodeToInsert) {
    Node* node;
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