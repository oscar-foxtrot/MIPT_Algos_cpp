/* Simple implementation of a queue (singly-linked list variation) */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

#include "singly_linked_list.hpp"

template <typename T>
class Queue: public SinglyLinkedList<T> {
public:

    void push(const T& value) { // Add to the tail
        this->insert(value);
    }

    T pop() {
        if (!this->head) {
            throw std::out_of_range("Queue<>::pop(): empty Queue");
        }
        T popped_elem = std::move(this->head->value);
        typename SinglyLinkedList<T>::Node* next = this->head->next;
        delete this->head;
        this->head = next;
        if (this->empty()) {
            this->tail = nullptr;
        }
        return popped_elem;
    }

    T front() {
        if (!this->head) {
            throw std::out_of_range("Queue<>::front(): empty Queue");
        }
        return this->head->value;
    }
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Queue<U>& lst);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
    os << "Queue(";
    typename SinglyLinkedList<T>::Node* current_node = queue.head;
    if (queue.head) {
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
