/* Simple implementation of the binomial heap data (Min Binomial Heap type) structure */

#ifndef BINOMIAL_HEAP_HPP
#define BINOMIAL_HEAP_HPP

#include <vector>
#include <memory>
#include <exception>

#include "tree.hpp"

template <typename T>
class BinomialHeap: public Tree<T> {
private:
    std::vector<std::shared_ptr<Tree<T>>> heap;
    std::vector<size_t> depths;

    void sift_down(std::shared_ptr<Tree<T>> tree_node) {
        if (!tree_node) {
            return;
        }
        size_t children_count = tree_node->get_children_count();
        if (!children_count) {
            return;
        }
        size_t min_index = 0;
        for (size_t i = 1; i < children_count; ++i) {
            if (tree_node->get_child(i)->get_value() < tree_node->get_child(min_index)->get_value()) {
                min_index = i;
            }
        }

        if (tree_node->get_child(min_index)->get_value() < tree_node->get_value()) {
            // swap
            T temp_val = tree_node->get_child(min_index)->get_value();
            tree_node->get_child(min_index)->set_value(tree_node->get_value());
            tree_node->set_value(temp_val);

            sift_down(tree_node->get_child(min_index));
        }
    }

    void sift_up(std::shared_ptr<Tree<T>> tree_node) {
        if (!tree_node || !tree_node->get_parent()) {
            return;
        }

        if (tree_node->get_parent()->get_value() > tree_node->get_value()) {
            // swap
            T temp_val = tree_node->get_value();
            tree_node->set_value(tree_node->get_parent()->get_value());
            tree_node->get_parent()->set_value(temp_val);

            sift_up(tree_node->get_parent());
        }
    }

    // |merge| invalidates the |other| heap
    void merge(BinomialHeap<T>& other) {

        std::shared_ptr<Tree<T>> temporary_tree_ptr = nullptr;
        size_t temporary_depth;
        BinomialHeap<T> result;

        size_t this_i = 0;
        size_t other_i = 0;

        /*
        1. Trees at iterators ARE of equal depth and temporary_tree_ptr ISN'T null? =>
        => temporary_tree_ptr goes into the result and the trees merge into one bigger tree and go into temporary_tree_ptr. Both iterators +1
            2. Trees at iterators ARE of equal depth and temporary_tree_ptr IS null? => 
        => nothing happens to the result and the trees merge into one bigger tree and go into temporary_tree_ptr. Both iterators +1
            3. Trees at iterators AREN'T of equal depth and temporary_tree_ptr IS null? => 
        => the tree with the smaller depth goes into the result. Only the corresponding iterator +1
            4. Trees at iterators AREN'T of equal depth and temporary_tree_ptr ISN'T null? => 
        =>      4.1: the depth of the shallower tree IS equal to temporary tree depth? =>
                => result stays unchanged. Both trees with the same depth are merged and placed into temporary_tree_ptr. It. of the heap with the "shallower" tree +1
                4.2: the depth of the shallower tree ISN'T equal to temporary tree depth? =>
                => temporary tree goes into the result. the shallower tree goes into the result. Iterator of the heap with the "shallower" tree +1
        */
        
        while ((this_i < heap.size()) || (other_i < other.heap.size())) {
            bool isnt_end_this = this_i < heap.size();
            bool isnt_end_other = other_i < other.heap.size();
            if (isnt_end_this && isnt_end_other && (depths[this_i] == other.depths[other_i])) {
                if (temporary_tree_ptr) {
                    // case (1)
                    result.heap.push_back(temporary_tree_ptr);
                    result.depths.push_back(temporary_depth);
                }
                // case (2) and the rest of case (1)
                temporary_depth = depths[this_i] + 1;
                if (heap[this_i]->get_value() < other.heap[other_i]->get_value()) {
                    temporary_tree_ptr = heap[this_i];
                    temporary_tree_ptr->add_child(other.heap[other_i]);
                } else {
                    temporary_tree_ptr = other.heap[other_i];
                    temporary_tree_ptr->add_child(heap[this_i]);
                }

                ++this_i;
                ++other_i;

            } else { // case when depths aren't equal (or exactly one of the heaps has been fully traversed)
                if (temporary_tree_ptr) { // case (4)
                    if (isnt_end_this && depths[this_i] == temporary_depth) { // case (4.1)
                        if (temporary_tree_ptr->get_value() < heap[this_i]->get_value()) {
                            temporary_tree_ptr->add_child(heap[this_i]);
                        } else {
                            heap[this_i]->add_child(temporary_tree_ptr);
                            temporary_tree_ptr = heap[this_i];
                        }
                        ++this_i;
                        ++temporary_depth;
                    } else if (isnt_end_other && other.depths[other_i] == temporary_depth) { // case (4.1) too
                        if (temporary_tree_ptr->get_value() < other.heap[other_i]->get_value()) {
                            temporary_tree_ptr->add_child(other.heap[other_i]);
                        } else {
                            other.heap[other_i]->add_child(temporary_tree_ptr);
                            temporary_tree_ptr = other.heap[other_i];
                        }
                        ++other_i;
                        ++temporary_depth;
                    } else { // case (4.2)
                        result.heap.push_back(temporary_tree_ptr);
                        result.depths.push_back(temporary_depth);
                        temporary_tree_ptr = nullptr;

                        if (!isnt_end_other || (isnt_end_this && depths[this_i] < other.depths[other_i])) {  // (also executes if the second one has been fully traversed)
                            result.heap.push_back(heap[this_i]);
                            result.depths.push_back(depths[this_i]);
                            ++this_i;
                        } else {  // (also executes if the first one has been fully traversed)
                            result.heap.push_back(other.heap[other_i]);
                            result.depths.push_back(other.depths[other_i]);
                            ++other_i;
                        }
                    }
                } else { // case (3)
                    if (!isnt_end_other || (isnt_end_this && depths[this_i] < other.depths[other_i])) {  // (also executes if the second one has been fully traversed)
                        result.heap.push_back(heap[this_i]);
                        result.depths.push_back(depths[this_i]);
                        ++this_i;
                    } else {  // (also executes if the first one has been fully traversed)
                        result.heap.push_back(other.heap[other_i]);
                        result.depths.push_back(other.depths[other_i]);
                        ++other_i;
                    }
                }
            }
        }

        if (temporary_tree_ptr) {
            result.heap.push_back(temporary_tree_ptr);
            result.depths.push_back(temporary_depth);
        }
        
        // invalidate the heaps
        heap.clear();
        depths.clear();
        other.heap.clear();
        other.depths.clear();

        heap = result.heap;
        depths = result.depths;
    }

public:

    BinomialHeap() = default;
    BinomialHeap(const T& value) {
        heap.push_back(std::make_shared<Tree<T>>(value));
        depths.push_back(1);
    }
    // Note that there's no copy constructor!
    // And the default one most likely will work in an undesired way

    size_t get_tree_count() const {
        return heap.size();
    }

    std::shared_ptr<Tree<T>> get_tree(size_t index) {
        if (index >= heap.size()) {
            throw std::out_of_range("BinomailHeap<>::get_tree(): out of range");
        }
        return heap[index];
    }

    size_t get_tree_depth(size_t index) const {
        if (index >= depths.size()) {
            throw std::out_of_range("BinomailHeap<>::get_tree_depth(): out of range");
        }
        return depths[index];
    }
    
    void decrease_key(std::shared_ptr<Tree<T>> tree_node, const T& by_how_much) {
        if (!tree_node) {
            return;
        }
        tree_node->set_value(tree_node->get_value() - by_how_much);
        sift_up(tree_node);
    }

    void increase_key(std::shared_ptr<Tree<T>> tree_node, const T& by_how_much) {
        if (!tree_node) {
            return;
        }
        tree_node->set_value(tree_node->get_value() + by_how_much);
        sift_down(tree_node);
    }

    bool empty() const {
        return heap.empty();
    }

    T get_min() const {
        if (heap.empty()) {
            throw std::out_of_range("BinomailHeap<>::get_min(): empty heap");
        }
        size_t min = 0;
        for (size_t i = 1; i < heap.size(); ++i) {
            if (heap[i]->get_value() < heap[min]->get_value()) {
                min = i;
            }
        }
        return heap[min]->get_value();
    }
    
    void insert(const T& value) {
        BinomialHeap<T> heap_to_merge(value);
        merge(heap_to_merge);
    }

    T extract_min() {
        if (heap.empty()) {
            throw std::out_of_range("BinomialHeap<>::extract_min(): empty heap");
        }
        size_t min = 0;
        for (size_t i = 1; i < heap.size(); ++i) {
            if (heap[i]->get_value() < heap[min]->get_value()) {
                min = i;
            }
        }
        T returned_element = heap[min]->get_value();
        
        BinomialHeap<T> heap_to_merge;

        for (size_t i = 0; i < heap[min]->get_children_count(); ++i) {
            heap_to_merge.heap.push_back(heap[min]->get_child(i));
            heap_to_merge.depths.push_back(i + 1);
        }

        heap.erase(heap.begin() + min);
        depths.erase(depths.begin() + min);

        merge(heap_to_merge);

        return returned_element;
    }
};

#endif