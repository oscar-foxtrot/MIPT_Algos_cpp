#include <iostream>

#include "../binary_search.hpp"
#include "../binary_search_pointer.hpp"
#include "../quicksort.hpp"

int main() {
    int length = 17;
    int arr[length] = {100, 30, 30, 92, 14, 63, 78, 55, 29, 87, 41, 6, 70, 23, 34, 59, 84};
    int test_arr_length = 20;
    int test_array[test_arr_length] = {1, 100, 30, 30, 92, 14, 63, 78, 55, 29, 87, 41, 6, 70, 23, 34, 59, 84, 1000, 10000};

    // Only can perform binary search on a sorted array!
    quicksort<int>(arr, length);

    for (int i = 0; i < test_arr_length; ++i) {
        std::cout << find<int>(test_array[i], arr, length) << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < test_arr_length; ++i) {
        std::cout << find_pointer<int>(test_array[i], arr, length) << ' ';
    }
    std::cout << std::endl << std::endl;
    return 0;
}
