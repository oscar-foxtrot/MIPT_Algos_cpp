#include <iostream>
#include <string>

#define your_file "mergesort.hpp"
#define your_sort mergesort

#include your_file

int main() {
    int length = 17;
    int arr[length] = {100, 30, 30, 92, 14, 63, 78, 55, 29, 87, 41, 6, 70, 23, 34, 59, 84};
    your_sort(arr, length);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << ' ';
    std::cout << std::endl << std::endl;
    return 0;
}
