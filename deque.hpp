/* Simple implementation of a deDeque (doubly-linked list variation) */

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>

#include "doubly_linked_list.hpp"

template <typename T>
class Deque: public DoublyLinkedList<T> {
public:

    void push_back(const T& value) { // Add to the tail
        this->insert(value);
    }

    void push_front(const T& value) { // Add to the tail
        if (!this->head) {
            this->insert(value);
            return;
        }
        ++this->length;
        typename DoublyLinkedList<T>::Node* new_node = new typename DoublyLinkedList<T>::Node(value);
        this->head->prev = new_node;
        new_node->next = this->head;
        new_node->prev = nullptr;
        new_node->value = value;
        this->head = new_node;
    }

    T pop_back() {
        if (!this->tail) {
            throw std::out_of_range("Deque<>::pop_back(): empty Deque");
        }
        --this->length;
        T popped_elem = std::move(this->tail->value);
        typename DoublyLinkedList<T>::Node* prev = this->tail->prev;
        delete this->tail;
        this->tail = prev;
        if (this->empty()) {
            this->head = nullptr;
        } else {
            this->tail->next = nullptr;
        }
        return popped_elem;
    }

    T pop_front() {
        if (!this->head) {
            throw std::out_of_range("Deque<>::pop_front(): empty Deque");
        }
        --this->length;
        T popped_elem = std::move(this->head->value);
        typename DoublyLinkedList<T>::Node* next = this->head->next;
        delete this->head;
        this->head = next;
        if (this->empty()) {
            this->tail = nullptr;
        } else {
            this->head->prev = nullptr;
        }
        return popped_elem;
    }

    T front() {
        if (!this->head) {
            throw std::out_of_range("Deque<>::front(): empty Deque");
        }
        return this->head->value;
    }

    T back() {
        if (!this->tail) {
            throw std::out_of_range("Deque<>::back(): empty Deque");
        }
        return this->tail->value;
    }
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Deque<U>& lst);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& Deque) {
    os << "Deque(";
    typename DoublyLinkedList<T>::Node* current_node = Deque.head;
    if (Deque.head) {
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
