/* Insertion Sort is an algorithm for sorting an array
Time complexity: O(n^2) - Worst case: O(n^2)
Space complexity: O(1) */

#include <cstddef>

/* Move a chunk of an array 1 element forward */
template <typename T>
void move_one_step_forward(T* begin, size_t length) {
    for (size_t i = length; i > 0; --i) {
        begin[i] = begin[i - 1];
    }
}

/* Sort an array of elements, for which the "<"" operator is defined,
via the Insertion Sort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void insertion_sort(T* arr, size_t arr_length) {
    for (size_t i = 1; i < arr_length; ++i) {
        size_t j = i;
        if (arr[i] < arr[j - 1]) {
            while (j > 0 && arr[i] < arr[j - 1]) {
                --j;
            }
            T elem_to_insert = arr[i];
            move_one_step_forward(arr + j, i - j);
            arr[j] = elem_to_insert;
        }
    }
}
