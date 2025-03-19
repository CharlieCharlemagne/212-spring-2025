#include "pqueue.hpp"
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char **argv) {
    PriorityQueue<std::pair<int, std::string> > pq(100);

    pq.enqueue(std::make_pair(10, "ten"));
    pq.enqueue(std::make_pair(35, "thirty five"));
    pq.enqueue(std::make_pair(15, "fifteen"));
    pq.enqueue(std::make_pair(25, "twenty five"));
    pq.enqueue(std::make_pair(20, "twenty"));
    pq.enqueue(std::make_pair(30, "thirty"));
    pq.enqueue(std::make_pair(4, "four"));
    pq.enqueue(std::make_pair(5, "five"));
    pq.enqueue(std::make_pair(6, "six"));
    pq.enqueue(std::make_pair(-100, "minus one hundred"));
    pq.enqueue(std::make_pair(100, "one hundred"));

    std::cout << "Size: " << pq.get_size() << std::endl;
    std::cout << "Capacity: " << pq.get_capacity() << std::endl;

    std::cout << "=> Testing the binary heap" << std::endl;
    while (!pq.empty()) {
        std::cout << pq.front().first << ": " <<  pq.front().second << "\n";
        pq.dequeue();
    }
    std::cout << std::endl;

    std::cout << "=> Testing the make_heap method" << std::endl;
    std::vector<int> vec = {10, 35, 15, 25, 20, 30, 4, 5, 6, -100, 100};
    PriorityQueue<int> heap(50);
    heap.make_heap(vec);
    while (!heap.empty()) {
        std::cout << heap.front() << "\n";
        heap.dequeue();
    }
    std::cout << std::endl;
    
    return 0;
}
