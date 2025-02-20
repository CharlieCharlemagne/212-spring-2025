#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

#include <cstddef> 

class DynamicArray {
    private:
        int *arr;                             // pointer to the (internal) array
        size_t capacity;                      // total number of elements that can be stored
        size_t size;                          // number of elements currently stored
        float growth_rate;                    // growth rate

    public:
        DynamicArray(float growth_rate);      // constructor
        ~DynamicArray();                      // destructor
        void push_back(int val);              // add an element to the end
        void pop_back();                      // remove the last element
        const int& operator[](size_t idx) const; // read-only access at a specific index
        int& operator[](size_t idx);             // access at a specific index (can modify)
        void insert(int val, size_t idx);        // insert an element at a specific index
        void erase(int uidx);                  // remove an element at a specific index
        void resize(int ulen);                 // change the capacity of the array
        size_t get_size();                           // return the number of elements
        size_t get_capacity();                       // return the capacity
        bool empty();                         // check if the array is empty
        void clear();                         // remove all elements, maintaining the capacity
        void print();                         // print the array

        // additional methods can be added here
};

#endif
