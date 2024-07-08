/* QuickSort is an algorithm for sorting an array.
There are multiple approaches to picking the so-called
"pivot" point. We'll be using the "median of 3" approach.
Time complexity: O(n*log(n)) - Worst case: O(n^2)
Space complexity: O(1) */

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <cstddef>
#include <utility>

namespace QuickSortModule {

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

}

/* Sort an array of elements, for which the "<"" operator is defined,
via the QuickSort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void quicksort(T* arr, size_t arr_length) {
    if (arr_length < 2) {
        return;
    }
    // partition the array. Get the dividing point index
    size_t divider_pos = QuickSortModule::partition(arr, arr_length);

    // sort left
    quicksort(arr, divider_pos);

    // sort right
    quicksort(arr + divider_pos + 1, arr_length - divider_pos - 1);
}

#endif
