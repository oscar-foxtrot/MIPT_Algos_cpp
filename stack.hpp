/* Simple implementation of a stack (singly-linked list variation) */

#include <iostream>
#include <exception>

template <typename T>
class Stack {
public:
    Stack() : head(nullptr) {}

    ~Stack() {
        // Destructor to clean up allocated memory
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push(const T& value) { // Add to the tail
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    T pop() {
        if (!head) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        T popped_elem = std::move(head->value);
        Node* next = head->next;
        delete head;
        head = next;
        return popped_elem;
    }

    bool empty() {
        return !head;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U>& lst);

private:
    struct Node {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& lst) {
    os << "Stack(";
    typename Stack<T>::Node* current_node = lst.head;
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
