/* MergeSort is an algorithm for sorting an array
Time complexity: O(n*log(n))
Space complexity: O(n) */


#include <memory>
#include <cstddef>

template <typename T>
void merge(T*, size_t, T*, size_t);

/* Sort an array of elements, for which the "<"" operator is defined,
via MergeSort algorithm. The original array is modified.
Order: ascending */
template <typename T>
void mergesort(T* arr, size_t arr_length) {
    if (arr_length == 1 or arr_length == 0) {
        return;
    }
    size_t midpoint = arr_length / 2;
    mergesort(arr, midpoint);
    mergesort(arr + midpoint, arr_length - midpoint);
    merge(arr, midpoint, arr + midpoint, arr_length - midpoint);
}

/* Merge procedure for sorted arrays */
template <typename T>
void merge(T* arr_0, size_t arr_0_length, T* arr_1, size_t arr_1_length) {
    std::unique_ptr<T[]> newarr = std::make_unique<T[]>(arr_0_length + arr_1_length);
    size_t nelem_0 = 0;
    size_t nelem_1 = 0;

    // Fill the new array (sort)
    size_t i = 0;
    while (nelem_0 < arr_0_length && nelem_1 < arr_1_length) {
        if (arr_1[nelem_1] < arr_0[nelem_0]) {
            newarr[i] = arr_1[nelem_1];
            ++nelem_1;
        } else {
            newarr[i] = arr_0[nelem_0];
            ++nelem_0;
        }
        ++i;
    }
    if (nelem_0 == arr_0_length) {
        for (size_t i = nelem_1; i < arr_1_length; ++i) {
            newarr[arr_0_length + i] = arr_1[i];
        }
    } else {
        for (size_t i = nelem_0; i < arr_0_length; ++i) {
            newarr[arr_1_length + i] = arr_0[i];
        }
    }

    // Copy the array into the original one 
    for (size_t i = 0; i < arr_0_length; ++i) {
        arr_0[i] = newarr[i];
    }
    for (size_t i = 0; i < arr_1_length; ++i) {
        arr_1[i] = newarr[arr_0_length + i];
    }
}
