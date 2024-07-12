#include <iostream>
#include <string>

#define your_file "mergesort.hpp"
#define your_sort mergesort

#include your_file

int main() {
    int arr[103] = {100, 30, 30, 92, 14, 63, 78, 55, 29, 87, 41, 6, 70, 23, 34, 59, 84, 10, 52, 92, 52, 97, 17, 45, 71, 3, 81, 10, 36, 68, 99, 13, 47, 79, 24, 64, 88, 9, 53, 26, 74, 38, 60, 86, 19, 33, 90, 15, 72, 98, 20, 57, 83, 11, 42, 67, 93, 4, 49, 75, 30, 65, 89, 7, 54, 25, 77, 18, 37, 91, 16, 73, 96, 21, 58, 85, 12, 50, 95, 31, 62, 82, 8, 44, 69, 2, 80, 35, 94, 22, 56, 76, 5, 48, 100, 32, 66, 40, 1, 43, 61, 28, 51};
    int length = 103;
    your_sort(arr, length);
    for (int i = 0; i < length; ++i) std::cout << arr[i] << ' ';
    std::cout << std::endl << std::endl;
    return 0;
}
