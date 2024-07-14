#include <iostream>

#include "../queue.hpp"

int main() {
    Queue<int> queue;
    queue.push(3);
    queue.push(5);
    queue.push(1);
    std::cout << queue << std::endl;
    std::cout << "Popped element: " << queue.pop() << std::endl;
    std::cout << queue << std::endl;
    queue.pop();
    std::cout << queue << ' ' << "Status: " << (queue.empty() ? "Empty" : "Not empty") << std::endl;
    std::cout << "Front: " << queue.front() << std::endl;
    queue.pop();
    std::cout << queue << ' ' << "Status: " << (queue.empty() ? "Empty" : "Not empty") << std::endl;
    return 0;
}
