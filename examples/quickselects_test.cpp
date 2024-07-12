#include <iostream>

#include "quickselect.hpp"
#include "dqs.hpp"

int main() {
    int length = 17;
    int arr[length] = {100, 30, 30, 92, 14, 63, 78, 55, 29, 87, 41, 6, 70, 23, 34, 59, 84};
    for (int i = 0; i < length; ++i) std::cout << dqs(arr, length, i + 1) << ' ';
    std::cout << std::endl << std::endl;
    for (int i = 0; i < length; ++i) std::cout << quickselect(arr, length, i + 1) << ' ';
    std::cout << std::endl << std::endl;
    return 0;
}
