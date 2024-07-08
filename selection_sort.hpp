/* Selection Sort is an algorithm for sorting an array
Time complexity: O(n^2) - Worst case: O(n^2)
Space complexity: O(1) */

#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <cstddef>

namespace SelectionSortModule {

/* Swap two elements (access by pointers) */
template <typename T>
void swap(T* a, T* b) {
    T c = *a;
    *a = *b;
    *b = c;
}

}

/* Sort an array of elements, for which the "<"" operator is defined,
via the Selection Sort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void selection_sort(T* arr, size_t arr_length) {
    for (size_t i = 0; i < arr_length - 1; ++i) {
        T* min_ptr = arr + i;
        for (size_t j = i; j < arr_length; ++j) {
            if (arr[j] < *min_ptr) {
                min_ptr = arr + j;
            }
        }
        if (min_ptr != arr + i) {
            SelectionSortModule::swap(min_ptr, arr + i);
        }
    }
}

#endif
