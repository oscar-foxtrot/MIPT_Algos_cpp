/* Simple implementation of singly-linked lists
Limited functionality (for example, one can add a fucntion to delete an element in O(n).
We omit all the unnecessary functionality for the sake of simplicity */

#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include <iostream>

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SinglyLinkedList() {
        // Destructor to clean up allocated memory
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const T& value) { // Add to the tail
        if (!head) {
            head = new Node(value);
            tail = head;
            return;
        }
        tail->next = new Node(value);
        tail = tail->next;
        tail->value = value;
        tail->next = nullptr;
    }

    bool empty() {
        return !head;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<U>& lst);

private:
    struct Node {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head; // Natural order preserved
    Node* tail; // insertion - O(1)
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& lst) {
    os << "SinglyLinkedList(";
    typename SinglyLinkedList<T>::Node* current_node = lst.head;
    if (lst.head) {
        os << current_node->value;
        while (current_node->next) {
            os << ", ";
            current_node = current_node->next;
            os << current_node->value;
        }
    }
    os << ")";
    return os;
}

#endif
