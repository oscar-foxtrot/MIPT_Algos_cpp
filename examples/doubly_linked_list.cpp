#include <iostream>

#include "..//doubly_linked_list.hpp"

int main() {
    DoublyLinkedList<int> lst;
    for (int i = 0; i < 10; ++i) {
        lst.insert(i);
    }
    std::cout << lst << ' ' << "Length: " << lst.get_length() << std::endl;
    lst.remove(9);
    std::cout << lst << ' ' << "Length: " << lst.get_length() << std::endl;
    lst.remove(4);
    lst.remove(0);lst.remove(0);lst.remove(0);lst.remove(0);lst.remove(0);lst.remove(0);lst.remove(0);
    std::cout << lst << ' ' << "Length: " << lst.get_length() << std::endl;
    lst.remove(0);
    std::cout << lst << ' ' << "Length: " << lst.get_length() << std::endl;
    return 0;
}
