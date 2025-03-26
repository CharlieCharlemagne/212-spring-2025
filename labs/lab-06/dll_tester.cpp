#include "doublylinkedlist.h"
#include <iostream>
#include <cassert>

void TestEmptyList() {
    DoublyLinkedList list;
    assert(list.empty() == true);
    assert(list.size() == 0);

    std::cout << "Empty list tests passed." << std::endl;
}

void TestInsertions() {
    DoublyLinkedList list;

    // test push_front
    list.push_front(10);
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);
    
    // test push_back
    list.push_back(20);
    assert(list.size() == 2);
    assert(list.front() == 10);
    assert(list.back() == 20);
    
    // test push_at
    list.push_at(1, 15);
    assert(list.size() == 3);
    assert(list.at(0) == 10);
    assert(list.at(1) == 15);
    assert(list.at(2) == 20);
    
    std::cout << "Insertion tests passed." << std::endl;
}

void TestDeletions() {
    DoublyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    
    // test pop_front
    list.pop_front();
    assert(list.size() == 3);
    assert(list.front() == 20);
    
    // test pop_back
    list.pop_back();
    assert(list.size() == 2);
    assert(list.back() == 30);
    
    // test pop_at
    list.push_back(50);  // List: 20, 30, 50
    list.pop_at(1);     // Remove 30
    assert(list.size() == 2);
    assert(list.at(0) == 20);
    assert(list.at(1) == 50);
    
    std::cout << "Deletion tests passed." << std::endl;
}

void TestEdgeCases() {
    DoublyLinkedList list;
    
    // test single element list
    list.push_front(10);
    assert(list.front() == 10);
    assert(list.back() == 10);
    
    // test removing from single element list
    list.pop_front();
    assert(list.empty() == true);
    
    // test operations after clearing
    list.push_back(20);
    list.push_back(30);
    list.push_front(10);
    list.push_front(40);
    list.push_at(0, 50);
    list.push_at(3, 60);
    list.clear();
    assert(list.empty() == true);
    list.push_front(5);
    assert(list.size() == 1);
    assert(list.empty() == false);
    
    std::cout << "Edge case tests passed." << std::endl;
}


void TestSearchFunctionality() {
    DoublyLinkedList list;
    
    // test searching in empty list
    assert(list.contains(10) == false);
    
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);
    
    // test finding existing elements
    assert(list.contains(10) == true);
    assert(list.contains(30) == true);
    assert(list.contains(50) == true);;
    
    // test searching for non-existent elements
    assert(list.contains(15) == false);
    assert(list.contains(100) == false);
    
    std::cout << "Basic search tests passed." << std::endl;
}

void TestTraversals() {
    DoublyLinkedList list;

    for (int i = 0 ; i < 100 ; i++) {
        list.push_back(i);
    }
    // test forward traversal
    for (int i = 0 ; i < 100 ; i+=10) {
        assert(list.at(i) == i);
    }
    // test reverse traversal
    for (int i = -1 ; i >= -100 ; i-=5) {
        assert(list.at(i) == 100+i);
    }

    std::cout << "Traversal tests passed." << std::endl;
}

void RunAllTests() {
    TestEmptyList();
    TestInsertions();
    TestDeletions();
    TestEdgeCases();
    TestSearchFunctionality();
    TestTraversals();

    std::cout << "All tests passed." << std::endl;
}

int main() {
    RunAllTests();
    return 0;
}
