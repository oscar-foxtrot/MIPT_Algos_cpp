/* Simple implementation of trees (not necessarily binary trees) */

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <memory>
#include <stdexcept>


template <typename T>
class Tree: public std::enable_shared_from_this<Tree<T>> {
private:
    std::weak_ptr<Tree> parent;
    std::vector<std::shared_ptr<Tree>> children;
    T root_value;

public:
    Tree() = default;

    Tree(const T& value): root_value(value) {}
    Tree(const T& value, std::shared_ptr<Tree> parent_ptr): root_value(value), parent(parent_ptr) {}

    void add_child(const T& value) {
        children.push_back(std::make_shared<Tree>(value, get_root()));
    }

    void remove_child(size_t index) {
        if (index >= children.size()) {
            throw std::invalid_argument("Tree<>::remove_child(): out of range");
        }
        children.erase(children.begin() + index);
    }

    std::shared_ptr<Tree> get_child(size_t index) {
        if (index >= children.size()) {
            throw std::invalid_argument("Tree<>::get_child(): out of range");
        }
        return children[index];
    }

    std::shared_ptr<Tree> get_root() {
        return this->shared_from_this();
    }

    std::shared_ptr<Tree<T>> get_parent() const {
        return parent.lock();  // Convert weak_ptr to shared_ptr
    }

    T get_value() const {
        return root_value;
    }

    void set_value(const T& value) {
        root_value = value;
    }

    size_t get_children_count() const {
        return children.size();
    }
};

#endif