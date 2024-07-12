/* QuickSort is an algorithm for sorting an array.
There are multiple approaches to picking the so-called
"pivot" point. We'll be using the "median of 3" approach.
Time complexity: O(n*log(n)) - Worst case: O(n*log(n))
Space complexity: O(n) */

#ifndef DETERMINISTICQUICKSORT_HPP
#define DETERMINISTICQUICKSORT_HPP

#include <cstddef>
#include <utility>
#include <memory>

#include "deterministic_quickselect.hpp"

/* Sort an array of elements, for which the "<"" operator is defined,
via the QuickSort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void dqsort(T* arr, size_t arr_length) {
    if (arr_length < 2) {
        return;
    }
    // partition the array. Get the dividing point index
    size_t divider_pos = DQSModule::partition(arr, arr_length);

    // sort left
    dqsort(arr, divider_pos);

    // sort right
    dqsort(arr + divider_pos + 1, arr_length - divider_pos - 1);
}

#endif
