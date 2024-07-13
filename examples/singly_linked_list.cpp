#include <iostream>

#include "../singly_linked_list.hpp"

int main() {
    SinglyLinkedList<int> lst;
    lst.insert(5);
    lst.insert(12);
    lst.insert(20);
    lst.insert(30);
    lst.insert(100);
    lst.insert(200);
    lst.insert(300);
    lst.insert(400);
    lst.insert(500);
    std::cout << lst;
    std::cout << std::endl;
    return 0;
}
