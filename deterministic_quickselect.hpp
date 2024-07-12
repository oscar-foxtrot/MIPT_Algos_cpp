/* QuickSelect (deterministic) is an algorithm for finding the k-th order statistic,
i.e. the k-th smallest element in an unsorted array of [comparable] elements.
The algorithm is akin to QuickSort, but a bit different
The pivot point is picked in a special way, so as the worst case is O(n),
not O(n^2), as in the traditional QuickSelect.
Even though the worst case asymptotics is less than in the traditional QS,
the average tiem complexity on random input is WORSE (in terms of the number of operations).
Time complexity: O(n) - Worst case: O(n)
Space complexity: O(n) */

#ifndef DETERMINISTICQUICKSELECT_HPP
#define DETERMINISTICQUICKSELECT_HPP

#include <cstddef>
#include <utility>
#include <stdexcept>
#include <memory>

#include "quickselect.hpp"

namespace DQSModule {

const size_t block_size_constant = 5;

/* Choose the median element from a block of size |block_size| starting at |arr| */
template <typename T>
T median(const T* arr, size_t block_size) {
    return quickselect(arr, block_size, block_size / 2 + 1);
}

/* In this version, the partition function is a bit modified (improved)
Comments show where it is */
template <typename T>
size_t partition(T* arr, size_t arr_length) {

    size_t b_length = arr_length / block_size_constant;
    T pivot;

    if (b_length != 0) {
        std::unique_ptr<T[]> b_arr = std::make_unique<T[]>(b_length);
        for (size_t i = 0; i < b_length; ++i) {
            b_arr[i] = median(arr + block_size_constant * i, block_size_constant);
        }
        pivot = median(b_arr.get(), b_length);
    } else {
        pivot = arr[0];
    }

    // modified: no moving the median (pivot) out of the way

    // modified: makes a copy, doesn't reference
    
    // Partition
    size_t position_to_insert = 0;
    for (size_t i = 0; i < arr_length; ++i) {
        if (arr[i] < pivot) {
            QuickSelectModule::swap(arr[i], arr[position_to_insert]);
            ++position_to_insert;
        }
    }
    
    // modified: find the pivot and move it to the predefined position
    // modified: doesn't move the pivot to the division point - different approach
    size_t pivot_pos;
    for (size_t i = position_to_insert; i < arr_length; ++i) {
        if (arr[i] == pivot) {
            pivot_pos = i;
            break;
        }
    }
    QuickSelectModule::swap(arr[pivot_pos], arr[position_to_insert]);

    return position_to_insert;
}


/* The DQS function */
template <typename T>
T dqs_subroutine(T* arr, size_t arr_length, size_t k_order) {
    if (arr_length == 0) {
        throw std::invalid_argument("Array is empty");
    } else if (k_order == 0) {
        throw std::invalid_argument("k must be 1 or greater");
    } else if (k_order > arr_length) {
        throw std::invalid_argument("k must be less than or equal to array length");
    } else if (arr_length == 1) {
        return arr[0];
    }

    // partition the array. Get the dividing point index
    size_t divider_pos = partition(arr, arr_length);

    if (divider_pos + 1 == k_order) {
        return arr[divider_pos];
    } else if (k_order < divider_pos + 1) {
        // search to the left
        return dqs_subroutine(arr, divider_pos, k_order);
    } else {
        // search to the right
        size_t offset = divider_pos + 1;
        return dqs_subroutine(arr + offset, arr_length - offset, k_order - offset);
    }
}

}

/* Find the k-th order statistic in an array of elements,
for which the "<" and "==" operators are defined,
via the QuickSelect algorithm.
The original array is not modified.
A copy of the statistics is returned.
Note: order starts from 1 */
template <typename T>
T dqs(const T* arr, size_t arr_length, size_t k_order) {
    std::unique_ptr<T[]> temp_arr = std::make_unique<T[]>(arr_length);
    for (size_t i = 0; i < arr_length; ++i) {
        temp_arr[i] = arr[i];
    }
    return DQSModule::dqs_subroutine(temp_arr.get(), arr_length, k_order);
}

#endif
