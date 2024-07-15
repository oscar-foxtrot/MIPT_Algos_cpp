#include <iostream>

#include "../deque.hpp"

int main() {
    Deque<int> deque;

    std::cout << std::endl << "-------- Part 0 -------" << std::endl;

    deque.push_front(3);
    deque.push_front(5);
    deque.push_front(1);
    std::cout << deque << std::endl;
    std::cout << "Popped element: " << deque.pop_front() << std::endl;
    std::cout << deque << std::endl;
    deque.pop_front();
    std::cout << deque << ' ' << "Status: " << (deque.empty() ? "Empty" : "Not empty") << std::endl;
    std::cout << "Front: " << deque.front() << std::endl;
    deque.pop_front();
    std::cout << deque << ' ' << "Status: " << (deque.empty() ? "Empty" : "Not empty") << std::endl;

    std::cout << std::endl << "-------- Part 1 -------" << std::endl;
    std::cout << deque << std::endl;
    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(30);
    std::cout << deque << " " << "Length: " << deque.get_length() << std::endl;
    std::cout << "Popped from the front: " << deque.pop_front() << std::endl;
    std::cout << deque << " " << "Length: " << deque.get_length() << std::endl;
    std::cout << "Popped from the back: " << deque.pop_back() << std::endl;
    std::cout << deque << " " << "Length: " << deque.get_length() << std::endl;
    int popped_elem = deque.pop_back();
    std::cout << deque << ' ' << "Popped from the back: " << popped_elem << std::endl;
    std::cout << "Length: " << deque.get_length() << " Status: " << (deque.empty() ? "Empty" : "Not empty") << std::endl;
    return 0;
}
