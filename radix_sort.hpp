/* Radix Sort (for numbers) is an algorithm for sorting an array of NUMBERS
Time complexity: O(n * log_{radix}{max(input)}) - Worst case: O(n * log_{radix}{max(input)})
When radix is small (let's say 10) then time complexity (both average and worst)
is O(n * log(k)) where k is the largest number in input array
Space complexity: O(radix + n) */

#ifndef RADIXSORT_HPP
#define RADIXSORT_HPP

#include <cstddef>
#include <memory>

namespace RadixModule {

/* Sort an array of *NON-NEGATIVE* *NUMBERS*
via the Counting Sort (for numbers) algorithm.
The original array is modified.
Order: ascending
Type: stable */
template <typename T>
void stable_counting_sort(T* arr, size_t arr_length, size_t radix, size_t radix_exponentiated) {
    // zero-initialized by default
    std::unique_ptr<size_t[]> counts = std::make_unique<size_t[]>(radix);

    for (size_t i = 0; i < arr_length; ++i) {
        ++counts[(arr[i] / radix_exponentiated) % radix];
    }

    // Modify counts so as it stores elements that are <= k for each elem at index k
    for (size_t i = 1; i < radix; ++i) {
        counts[i] += counts[i - 1];
    }

    std::unique_ptr<T[]> answer = std::make_unique<T[]>(arr_length);
    for (size_t i = arr_length; i > 0; --i) {
        T& x = arr[i - 1];
        answer[counts[(x / radix_exponentiated) % radix] - 1] = x;
        --counts[(x / radix_exponentiated) % radix];
    }

    for (size_t i = 0; i < arr_length; ++i) {
        arr[i] = answer[i];
    }
}

}

/* Sort an array of *NON-NEGATIVE* *NUMBERS*
via the Radix Sort (for numbers) algorithm. The original array is modified.
The variation used is LSD (least significant digit)
It is guaranteed to correctly sort an array with the maximum being under |SIZE_MAX / radix|
Therefore, if no maximum cap value is known, pick radix=2
Order: ascending
Type: stable */
template <typename T>
void radix_sort(T* arr, size_t arr_length, size_t radix=10) {
    if (arr_length < 2) {
        return;
    }
    T max = arr[0];
    for (size_t i = 0; i < arr_length; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    size_t radix_exponentiated = 1;
    while (0 < max / radix_exponentiated) {
        RadixModule::stable_counting_sort(arr, arr_length, radix, radix_exponentiated);
        radix_exponentiated *= radix;
    }
}

#endif
