#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <iomanip>

#include "dyn-array.h"

void time_func(DynamicArray& array, size_t n, float gr) {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0 ; i < n ; i++) {
        array.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Capacity: " << array.get_capacity() << "\tSize: " << array.get_size() << "\tRate: " << gr << "\t" << (double) elapsed.count() << " seconds" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }
    DynamicArray arr(2);
    for (int i = 0 ; i < 12 ; i++) {
        arr.push_back(i*10);
    }
    arr.print();

    DynamicArray array_1(2.0); // grows 100% every time it reaches full capacity
    DynamicArray array_2(1.75); // grows 75% every time it reaches full capacity
    DynamicArray array_3(1.5); // grows 50% every time it reaches full capacity
    DynamicArray array_4(1.25); // grows 25% every time it reaches full capacity
    DynamicArray array_5(1.1); // grows 10% every time it reaches full capacity
    // get argument from command line (how many consecutive appends?)
    size_t n = atoi(argv[1]);
    // measure time for each call
    time_func(array_1, n, 2.0);
    time_func(array_2, n, 1.75);
    time_func(array_3, n, 1.5);
    time_func(array_4, n, 1.25);
    time_func(array_5, n, 1.1);

    return 0;
}

