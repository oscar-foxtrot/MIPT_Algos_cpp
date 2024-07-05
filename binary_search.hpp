#include <cstddef>

/* Find an element in a SORTED array of elemets,
for which operators "<" and "==" are defined,
using the binary search algorithm */
template <typename T>
bool find(const T& elem, const T* arr, size_t arr_length) {
    if (arr_length == 0) {
        return false;
    }
    size_t start = 0;
    size_t end = arr_length;
    while (end - start > 1) {
        // Calculate the center of the array
        size_t midpoint = start + (end - start) / 2;
        const T* pointer = arr + midpoint;

        // Localize the search space or terminate upon finding
        if (arr[midpoint] == elem) {
            return true;
        } else if (arr[midpoint] < elem) {
            start = midpoint + 1;
        } else {
            end = midpoint;
        }
    }
    if ((end != start) && (elem == arr[start])) {
        return true;
    }
    return false;
}
