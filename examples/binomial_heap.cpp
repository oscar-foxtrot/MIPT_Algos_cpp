#include <iostream>
#include "../binomial_heap.hpp"

int main() {
	BinomialHeap<int> heap;
	heap.insert(5);
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;
	heap.insert(2);
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;
	heap.insert(3);
	
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;
	heap.insert(3);
	
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;
	heap.insert(3);
	
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;
	heap.insert(3);
	
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;
	heap.insert(3);
	
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;

	heap.insert(1);
	
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;

	std::cout << "min" << heap.extract_min() << "min" << std::endl;
	for (int i = 0; i < heap.get_tree_count(); ++i) {
		std::cout << ' ' << heap.get_tree_depth(i);
	}
	std::cout << std::endl;

	std::shared_ptr<Tree<int>> tr = heap.get_tree(2);


	heap.increase_key(tr, 2);
	std::cout << tr->get_value();
	std::cout << tr->get_child(0)->get_value();
	std::cout << tr->get_child(1)->get_value();
	std::cout << tr->get_child(1)->get_child(0)->get_value();
	std::cout << std::endl;

	heap.increase_key(tr->get_child(1)->get_child(0), 2);
	std::cout << tr->get_value();
	std::cout << tr->get_child(0)->get_value();
	std::cout << tr->get_child(1)->get_value();
	std::cout << tr->get_child(1)->get_child(0)->get_value();
	std::cout << std::endl;

	heap.decrease_key(tr->get_child(1)->get_child(0), 4);
	std::cout << tr->get_value();
	std::cout << tr->get_child(0)->get_value();
	std::cout << tr->get_child(1)->get_value();
	std::cout << tr->get_child(1)->get_child(0)->get_value();
	std::cout << std::endl;
	
	return 0;
}
