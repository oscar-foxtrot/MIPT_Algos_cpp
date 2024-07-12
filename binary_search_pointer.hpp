#ifndef BINARYSEARCHPOINTER
#define BINARYSEARCHPOINTER

#include <cstddef>

/* Find the pointer of an element in a SORTED array of elemets,
for which operators "<" and "==" are defined,
using the binary search algorithm */
template <typename T>
T* find_pointer(const T& elem, T* arr, size_t arr_length) {
    if (arr_length == 0) {
        return nullptr;
    }
    size_t start = 0;
    size_t end = arr_length;
    while (end != start) {
        // Calculate the center of the array
        size_t midpoint = start + (end - start) / 2;

        // Localize the search space or terminate upon finding
        if (arr[midpoint] == elem) {
            return arr + midpoint;
        } else if (arr[midpoint] < elem) {
            start = midpoint + 1;
        } else {
            end = midpoint;
        }
    }
    return nullptr;
}

#endif
