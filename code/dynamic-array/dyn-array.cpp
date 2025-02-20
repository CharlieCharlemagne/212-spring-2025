#include "dyn-array.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

// constructor: default
DynamicArray::DynamicArray(float gr) {
    arr = nullptr;
    capacity = 0;
    size = 0;
    growth_rate = gr;
}

// destructor
DynamicArray::~DynamicArray() {
    if (arr != nullptr) {
        delete [] arr;
    }
}

// add an element to the end
void DynamicArray::push_back(int val) {
    if (size == capacity) {
        resize((size_t) std::ceil(capacity * growth_rate));
    }
    arr[size] = val;
    size++;
}

// remove the last element
void DynamicArray::pop_back() {
    if (size > 0) {
        size--;
    }
}

// change the capacity of the array
void DynamicArray::resize(int len) {
    if (len < size) throw std::out_of_range("New capacity is less than current size");
    // consider edge case when array is empty (pointing to nullptr)
    if (len == 0) len = 1;
    // allocate new array
    int *new_arr = new int[len];
    // check if allocation was successful
    if (new_arr == nullptr) throw std::bad_alloc();
    // copy elements
    for (int i = 0 ; i < size ; i++) {
        new_arr[i] = arr[i];
    }
    // deallocate old array
    if (arr != nullptr) delete [] arr;
    // update array pointer and capacity
    arr = new_arr;
    capacity = len;
}

// read-only access at a specific index
const int& DynamicArray::operator[](size_t idx) const {
    return arr[idx];
} 

// access at a specific index (can modify)
int& DynamicArray::operator[](size_t idx) {
    return arr[idx];
}

// insert an element at a specific index
void DynamicArray::insert(int val, size_t idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Index out of range");
    if (size == capacity) {
        resize((size_t) std::ceil(capacity * growth_rate));
    }
    for (int i = size ; i > idx ; i--) {
        arr[i] = arr[i - 1];
    }
    arr[idx] = val;
    size++;
}

// remove an element at a specific index
void DynamicArray::erase(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    for (int i = idx ; i < size - 1 ; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// return the number of elements
size_t DynamicArray::get_size() {
    return size;
}

// return the capacity
size_t DynamicArray::get_capacity() {
    return capacity;
}

// check if the array is empty
bool DynamicArray::empty() {
    return size == 0;
}        

// remove all elements, maintaining the capacity
void DynamicArray::clear() {
    size = 0;
}

// print the array
void DynamicArray::print() {
    for (int i = 0 ; i < capacity ; i++) {
        if (i < size) {
            std::cout << arr[i] << " ";
        } else {
            std::cout << "X ";
        }
    }
    std::cout << std::endl;
}