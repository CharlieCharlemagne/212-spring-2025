#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include <cstddef>
#include <stdexcept>
#include <vector>

// - class implements a priority queue using a MAX binary heap
// each element in `arr` is a value that will be used as the key;
// - as templates are used, the type of the key is not specified;
// - if a std::pair is used, the key is the first element of the pair
// and the value is the second element of the pair.
template <typename T>
class PriorityQueue {
    private:
        T *arr;
        size_t capacity;
        size_t size;

        size_t parent(size_t i) { return (i-1) / 2; }
        size_t left(size_t i) { return 2*i + 1; }
        size_t right(size_t i) { return 2*i + 2; }

        void upHeap(size_t i);
        void downHeap(size_t i);

    public:
        PriorityQueue(size_t cap);
        ~PriorityQueue();

        void enqueue(const T& val);
        void dequeue();
        T& front();
        void make_heap(const std::vector<T>& vec);

        size_t get_size() { return size; }
        size_t get_capacity() { return capacity; }
        bool empty() { return size == 0; }
};

template <typename T>
PriorityQueue<T>::PriorityQueue(size_t cap) {
    capacity = cap;
    size = 0;
    arr = new T[capacity];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete [] arr;
}

template <typename T>
void PriorityQueue<T>::upHeap(size_t i) {
    if (i > 0) {
        size_t p = parent(i);
        if (arr[p] < arr[i]) {
            std::swap(arr[p], arr[i]);
            upHeap(p);
        }
    }
}

template <typename T>
void PriorityQueue<T>::downHeap(size_t i) {
    size_t largest = i;
    size_t l = left(i);
    size_t r = right(i);

    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        downHeap(largest);
    }
}

template <typename T>
void PriorityQueue<T>::enqueue(const T& val) {
    // TODO:
    // 1. if the array is full, throw an out_of_range exception
    // 2. append element to the end of the array
    // 3. update size
    // 4. call upHeap making sure the heap property is maintained
}

template <typename T>
void PriorityQueue<T>::dequeue() {
    // TODO:
    // 1. if the array is empty, throw an out_of_range exception
    // 2. replace the root with the last element
    // 3. update size
    // 4. call downHeap making sure the heap property is maintained
}

template <typename T>
T& PriorityQueue<T>::front() {
    // TODO:
    // 1. if the array is empty, throw an out_of_range exception
    // 2. return the root element
}

template <typename T>
void PriorityQueue<T>::make_heap(const std::vector<T>& vec) {
    // TODO:
    // 1. if vector is larger than capacity, throw an out_of_range exception
    // 2. copy the elements of the vector to the array
    // 3. update size
    // 4. starting from the last non-leaf node to the root, call downHeap
    // to make sure the heap property is maintained
}

#endif
