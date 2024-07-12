/* Counting Sort (for numbers) is an algorithm for sorting an array of NUMBERS
Time complexity: O(n + k) - Worst case: O(n + k)
Space complexity: O(n + k) */

#ifndef STABLECOUNTINGSORT_HPP
#define STABLECOUNTINGSORT_HPP

#include <cstddef>
#include <utility>

/* Sort an array of *NON-NEGATIVE* *NUMBERS*
via the Counting Sort (for numbers) algorithm.
The original array is modified.
Order: ascending
Type: stable */
template <typename T>
void stable_counting_sort(T* arr, size_t arr_length) {
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

    // Modify counts so as it stores elements that are <= k for each elem at index k
    for (size_t i = 1; i < max + 1; ++i) {
        counts[i] += counts[i - 1];
    }

    std::unique_ptr<T[]> answer = std::make_unique<T[]>(arr_length);
    for (size_t i = arr_length; i > 0; --i) {
        T& x = arr[i - 1];
        answer[counts[x] - 1] = x;
        --counts[x];
    }
    for (size_t i = 0; i < arr_length; ++i) {
        arr[i] = answer[i];
    }
}

#endif
