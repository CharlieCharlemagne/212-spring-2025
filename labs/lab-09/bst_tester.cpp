#include <iostream>
#include <random>
#include <vector>
#include <cassert>
#include "bst.hpp"

int main() {
    BST<int> tree;
    std::vector<int> test_keys = {10, 5, 15, 3, 7, 3, 7, 3, 7, 3, 7};

    for (const auto& key : test_keys) {
        tree.insert(key);
    }

    assert(tree.get_size() == 5); // 10, 5, 15, 3, 7 are unique keys
    assert(tree.search(10) == true);
    assert(tree.search(3) == true);
    assert(tree.search(20) == false);
    tree.remove(5);
    assert(tree.search(5) == false);
    tree.print_in_order();

    tree.clear();
    tree.insert(20);
    tree.insert(25);

    assert(tree.get_size() == 2);
    assert(tree.search(20) == true);
    assert(tree.search(25) == true);
    assert(tree.search(30) == false);
    tree.print_in_order();

    tree.clear();
    assert(tree.get_size() == 0);

    test_keys.clear();
    for (int i = 1 ; i <= 10000 ; ++i) {
        test_keys.push_back(i);
    }
    std::shuffle(test_keys.begin(), test_keys.end(), std::default_random_engine(5));
    for (const auto& key : test_keys) {
        tree.insert(key);
    }

    assert(tree.get_size() == 10000);
    std::shuffle(test_keys.begin(), test_keys.end(), std::default_random_engine(5));
    for (const auto& key : test_keys) {
        tree.remove(key);
        if (key % 500 == 0) {
            assert(tree.search(key) == false);
        }
    }
    assert(tree.get_size() == 0);

    // TODO
    // Add tests for the get_height method

    return 0;
}