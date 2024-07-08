/* QuickSelect is an algorithm for finding the k-th order statistic,
i.e. the k-th smallest element in an unsorted array of [comparable] elements.
The algorithm is akin to QuickSort, but a bit different
There are multiple approaches to picking the so-called
"pivot" point. We'll be using the "median of 3" approach.
Time complexity: O(n) - Worst case: O(n^2)
Space complexity: O(n) */

#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <cstddef>
#include <utility>
#include <stdexcept>

namespace QuickSelectModule {

/* Choose the median element */
template <typename T>
T& median(T& a, T& b, T& c) {
    if (a < b) {
        if (b < c) {
            return b;
        } else if (a < c) {
            return c;
        } else {
            return a;
        }
    } else {
        if (c < b) {
            return b;
        } else if (c < a) {
            return c;
        } else {
            return a;
        }
    }
}

/* Swap two elements */
template <typename T>
void swap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

/* Partition the array. Return the pivot point index */
template <typename T>
size_t partition(T* arr, size_t arr_length) {

    // Move the median (pivot) out of the way - to the end
    swap(median(arr[0], arr[arr_length - 1], arr[arr_length / 2]), arr[arr_length - 1]);
    T& pivot = arr[arr_length - 1];
    
    // Partition
    size_t position_to_insert = 0;
    for (size_t i = 0; i < arr_length - 1; ++i) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[position_to_insert]);
            ++position_to_insert;
        }
    }

    // Move pivot to the division point
    swap(pivot, arr[position_to_insert]);

    return position_to_insert;
}

/* The quickselect function */
template <typename T>
T quickselect_subroutine(T* arr, size_t arr_length, size_t k_order) {
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
        return quickselect_subroutine(arr, divider_pos, k_order);
    } else {
        // search to the right
        return quickselect_subroutine(arr + divider_pos + 1, arr_length - divider_pos - 1, k_order - divider_pos - 1);
    }
}

}

/* Find the k-th order statistic in an array of elements,
for which the "<"" operator is defined,
via the QuickSelect algorithm.
The original array is not modified.
A copy of the statistics is returned.
Note: order starts from 1 */
template <typename T>

T quickselect(T* arr, size_t arr_length, size_t k_order) {
    // Allocate memory for a copy of the input array
    T* temp_arr = new T[arr_length];
    try {
        for (size_t i = 0; i < arr_length; ++i) {
            temp_arr[i] = arr[i];
        }
        return QuickSelectModule::quickselect_subroutine(temp_arr, arr_length, k_order);
    } catch (...) {
        // Free memory in case of any exception
        delete[] temp_arr;
        throw; // Re-throw the exception to propagate it further
    }
    // Clean up dynamically allocated memory
    delete[] temp_arr;
}

#endif
