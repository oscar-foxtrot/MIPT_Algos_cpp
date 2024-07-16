#include <iostream>

#include "../heap.hpp"

int main() {
    int arr[] = {4,3,2,1};
    Heap<int> heap1(arr, 4);
    std::cout << heap1 << std::endl; // checking heapify

    Heap<int> heap;
    heap.insert(10);
    heap.insert(2);
    heap.insert(3);
    heap.insert(111);
    heap.insert(20);
    heap.insert(30);
    heap.insert(1);
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;
    heap.decrease_key(3, 10);
    std::cout << heap << std::endl;
    heap.decrease_key(1, 20);
    std::cout << heap << std::endl;
    heap.decrease_key(1, 100);
    std::cout << heap << std::endl;
    heap.decrease_key(3, 200);
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;
    std::cout << "Extracted min: " << heap.extract_min() << std::endl;
    std::cout << heap << std::endl;

    return 0;
}
