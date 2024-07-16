/* Simple implementation of the heap data (Min Heap type) structure */

#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <exception>
#include <iostream>

template <typename T>
class Heap {
private:

    std::vector<T> heap;

    void sift_down(size_t index) {
        if (heap.size() < 2 * (index + 1)) {
            return;
        }
        size_t min = 2 * (index + 1) - 1;
        if (heap.size() > 2 * (index + 1) && (heap[2 * (index + 1)] < heap[2 * (index + 1) - 1])) {
            min = 2 * (index + 1);
        }

        if (heap[min] < heap[index]) {
            std::swap(heap[index], heap[min]);
            sift_down(min);
        }
    }

    void sift_up(size_t index) {
        if (index == 0) {
            return;
        }
        size_t parent_node_number = (index + 1) / 2 - 1;
        if (heap[index] < heap[parent_node_number]) {
            std::swap(heap[index], heap[parent_node_number]);
            sift_up(parent_node_number);
        }
    }

public:
    void insert(const T& value) { // Add to the tail
        heap.push_back(value);
        sift_up(heap.size() - 1);
    }

    T get_min() {
        if (heap.empty()) {
            throw std::out_of_range("Heap<>::get_min(): empty heap");
        }
        return heap[0];
    }

    T extract_min() {
        if (heap.empty()) {
            throw std::out_of_range("Heap<>::extract_min(): empty heap");
        }
        std::swap(heap[0], heap[heap.size() - 1]);
        T returned_element = heap.back();
        heap.pop_back();
        sift_down(0);
        return returned_element;
    }

    void decrease_key(size_t index, T by_delta) {
        if (index + 1 > heap.size()) {
            throw std::out_of_range("Heap<>::decrease_key(): out of range");
        }
        heap[index] -= by_delta;
        sift_up(index);
    }

    void increase_key(size_t index, T by_delta) {
        if (index + 1 > heap.size()) {
            throw std::out_of_range("Heap<>::increase_key(): out of range");
        }
        heap[index] += by_delta;
        sift_down(index);
    }

    size_t get_length() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Heap<U>& heap);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Heap<T>& heap) {
    os << "Heap(";
    if (heap.heap.size() == 0) {
        os << ")";
        return os;
    }
    std::cout << heap.heap[0];
    for (size_t i = 1; i < heap.heap.size(); ++i) {
        std::cout << ", " << heap.heap[i];
    }
    os << ")";
    return os;
}

#endif
