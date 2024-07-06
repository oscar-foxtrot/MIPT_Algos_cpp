/* Bubble Sort is an algorithm for sorting an array
Time complexity: O(n^2) - Worst case: O(n^2)
Space complexity: O(1) */

#include <cstddef>

/* Swap two elements */
template <typename T>
void swap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

/* Sort an array of elements, for which the "<"" operator is defined,
via the Bubble Sort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void bubble_sort(T* arr, size_t arr_length) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < arr_length; ++i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
    } while (swapped);
}
