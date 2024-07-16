/* HeapSort is an algorithm for sorting an array of elements (in-place)
Time complexity: O(n*log(n)) - Worst case: O(n*log(n))
Space complexity: O(1) */

#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <cstddef>
#include <utility>

namespace HeapSortModule {

template <typename T>
void sift_down(T* heap, size_t arr_length, size_t index) {
    if (arr_length < 2 * (index + 1)) {
        return;
    }
    size_t min = 2 * (index + 1) - 1;
    if (arr_length > 2 * (index + 1) && (heap[2 * (index + 1)] < heap[2 * (index + 1) - 1])) {
        min = 2 * (index + 1);
    }

    if (heap[min] < heap[index]) {
        std::swap(heap[index], heap[min]);
        sift_down(heap, arr_length, min);
    }
}

/* Transform the array into a heap */
template <typename T>
void heapify(T* arr, size_t arr_length) {
    if (arr_length == 0) {
        return;
    }
    for (size_t i = arr_length; i > 0; --i) {
        sift_down(arr, arr_length, i - 1);
    }
}

template <typename T>
void sort_heap(T* arr, size_t arr_length) {
    for (size_t i = arr_length; i > 0; --i) { // |n| times
        std::swap(arr[0], arr[i - 1]);
        sift_down(arr, i - 1, 0); // O(logn)
    }
}

}

/* Sort an array of elements, for which the "<" operator is defined,
via the HeapSort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void heapsort(T* arr, size_t arr_length, bool ascending=true) {
    HeapSortModule::heapify(arr, arr_length);
    HeapSortModule::sort_heap(arr, arr_length);
    if (ascending) {
        for (size_t i = 0; i < arr_length / 2; ++i) {
            std::swap(arr[i], arr[(arr_length - 1) - i]);
        }
    }
}

#endif
