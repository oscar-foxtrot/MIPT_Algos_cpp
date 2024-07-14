#include <iostream>

#include "../stack.hpp"

int main() {
    Stack<int> stack;
    stack.push(3);
    stack.push(5);
    stack.push(1);
    std::cout << stack << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << stack << std::endl;
    stack.pop();
    std::cout << stack << ' ' << "Status: " << (stack.empty() ? "Empty" : "Not empty") << std::endl;
    stack.pop();
    std::cout << stack << ' ' << "Status: " << (stack.empty() ? "Empty" : "Not empty") << std::endl;
    return 0;
}
