/* Counting Sort (for numbers) is an algorithm for sorting an array of NUMBERS
Time complexity: O(n + k) - Worst case: O(n + k)
Space complexity: O(k) */

#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include <cstddef>
#include <memory>

/* Sort an array of *NON-NEGATIVE* *NUMBERS*
via the Counting Sort (for numbers) algorithm. The original array is modified.
Order: ascending */
template <typename T>
void counting_sort(T* arr, size_t arr_length) {
    if (arr_length < 2) {
        return;
    }
    T max = arr[0];
    for (size_t i = 1; i < arr_length; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    // zero-initialized by default
    std::unique_ptr<size_t[]> counts = std::make_unique<size_t[]>(max + 1);

    for (size_t i = 0; i < arr_length; ++i) {
        ++counts[arr[i]];
    }
    
    size_t index = 0;
    for (T k = 0; k <= max; ++k) {
        for (size_t i = 0; i < counts[k]; ++i) {
            arr[index] = k;
            ++index;
        }
    }
}

#endif
