#include "list.hpp"
#include <iostream>

int main(int argc, char **argv) {
    SLList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_front();
    // list.push_front(1);
    // list.push_front(2);
    // list.push_front(3);
    // list.pop_back();

    std::cout << "Size: " << list.get_size() << std::endl;

    list.print();

    return 0;
}

