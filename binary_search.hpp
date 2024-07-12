/* Binary Search is an algorithm for searching elements in a sorted array
Time complexity: O(log(n)) - Worst case: O(log(n)) */

#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <cstddef>

/* Find an element in a SORTED array of elemets,
for which operators "<" and "==" are defined,
using the binary search algorithm */
template <typename T>
bool find(const T& elem, const T* arr, size_t arr_length) {
    if (arr_length == 0) {
        return false;
    }
    size_t start = 0;
    size_t end = arr_length;
    while (end != start) {
        // Calculate the center of the array
        size_t midpoint = start + (end - start) / 2;

        // Localize the search space or terminate upon finding
        if (arr[midpoint] == elem) {
            return true;
        } else if (arr[midpoint] < elem) {
            start = midpoint + 1;
        } else {
            end = midpoint;
        }
    }
    return false;
}

#endif
