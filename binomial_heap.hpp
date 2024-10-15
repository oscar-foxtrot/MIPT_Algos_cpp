/* Simple implementation of the binomial heap data (Min Binomial Heap type) structure */

#ifndef BINOMIAL_HEAP_HPP
#define BINOMIAL_HEAP_HPP

#include <vector>
#include <memory>

#include "tree.hpp"

template <typename T>
class BinomialHeap: public Tree<T> {
private:
    std::vector<std::shared_ptr<Tree<T>>> heap;

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

    BinomialHeap() = default;
    BinomialHeap(const T& value) {
        heap.push_back(std::make_shared<Tree<T>>(value));
    }

    T get_min() const {
        T min = heap[0]->get_value();
        for (size_t i = 1; i < heap.size(); ++i) {
            if (heap[i]->get_value() < min) {
                min = heap[i]->get_value();
            }
        }
        return min;
    }
    
    insert(const T& value) {
        
    }
};

#endif
