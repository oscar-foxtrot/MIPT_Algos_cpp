/* Simple implementation of doubly-linked lists */

#include <iostream>

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~DoublyLinkedList() {
        // Destructor to clean up allocated memory
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    size_t get_length() {
        return length;
    }

    void insert(const T& value) { // Add to the tail
        ++length;
        if (!head) {
            head = new Node(value);
            tail = head;
            return;
        }
        Node* new_node = new Node(value);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        tail->value = value;
        tail->next = nullptr;
    }
    
    // If no element with such index exists, terminate the program (implicit)
    void remove(size_t index) {
        Node* current_node = head;
        for (size_t i = 0; i < index; ++i) {
            current_node = current_node->next;
        }
        Node* next = current_node->next;
        Node* prev = current_node->prev;
        --length;
        if (current_node == head || current_node == tail) {
            if (current_node == head) {
                head = next;
                if (head) {
                    head->prev = nullptr;
                }
            }
            if (current_node == tail) {
                tail = prev;
                if (tail) {
                    tail->next = nullptr;
                }
            }
        } else {
            prev->next = next;
            next->prev = prev;
        }
        delete current_node;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& lst);

private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(const T& value) : value(value), next(nullptr), prev(nullptr) {}
    };

    Node* head; // Natural order preserved
    Node* tail; // insertion - O(1)
    size_t length;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& lst) {
    os << "DoublyLinkedList(";
    typename DoublyLinkedList<T>::Node* current_node = lst.head;
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
