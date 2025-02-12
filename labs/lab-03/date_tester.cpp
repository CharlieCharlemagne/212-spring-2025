#include "date.h"
#include <iostream>

int main() {
    // create a Date object (variable) using the default constructor
    Date d1;
    d1.print(); // should print 01/01/2000

    // create a Date object using the parameterized constructor
    Date d2(31, 12, 1999);
    d2.print(); // should print 12/31/1999

    d1.add_days(1);
    d1.print(); // should print 01/02/2000

    d1.add_days(40);
    d1.print(); // should print 02/11/2000

    // can also use the overloaded += operator to add days
    d1 += 80;
    d1.print(); // should print 05/01/2000

    d1 += 800;
    d1.print(); // should print 07/10/2002

    // compare two dates using the overloaded == operator
    if (d1 == d2) {
        std::cout << "d1 and d2 are equal" << std::endl;
    } else {
        std::cout << "d1 and d2 are not equal" << std::endl;
    }

    // compare two dates using the overloaded != operator
    if (d1 != d2) {
        std::cout << "d1 and d2 are not equal" << std::endl;
    } else {
        std::cout << "d1 and d2 are equal" << std::endl;
    }

    // compare two dates using the overloaded < operator
    if (d1 < d2) {
        std::cout << "d1 is less than d2" << std::endl;
    } else {
        std::cout << "d1 is not less than d2" << std::endl;
    }
    
    /***********************************************
    TODO:
    - add 5 additional test cases to test the class 
    methods and the overloaded operators
    - try to test edges cases, such as:
    - adding days to the end of a month
    - adding days to the end of a year
    ***********************************************/

    // create a pointer to a date object
    Date *d3;
    // dynamically allocate memory for an array of 5 date objects
    d3 = new Date[5];
    // add 14 days to each date and print it
    for (int i = 0; i < 5; i++) {
        d3[i] += (14 * i);
        d3[i].print();
    }
    // free the memory allocated for the array of date objects
    delete [] d3;

    return 0;
}
