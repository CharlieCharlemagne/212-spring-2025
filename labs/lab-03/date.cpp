#include "date.h"
#include <iostream>
#include <cassert>

// default constructor
Date::Date() {
    std::cout << "Default constructor called" << std::endl;
    /***********************************************
    TODO: initialize the date to January 1, 2000
    ***********************************************/
}

// parameterized constructor
Date::Date(int d, int m, int y) {
    std::cout << "Parameterized constructor called" << std::endl;
    /***********************************************
    TODO: initialize the date to the given values
    use `throw`, to throw an exception if the date is invalid (use is_valid_date())
    ***********************************************/
}

// destructor
Date::~Date() {
    std::cout << "Destructor called" << std::endl;
}

bool Date::is_valid_date(int d, int m, int y) {
    if (y < 1 || m < 1 || d < 1 || m > 12) {
        return false;
    }
    if (d > days_in_month(m, y)) {
        return false;
    }
    return true;
}

int Date::days_in_month(int m, int y) {
    /***********************************************
    TODO: return the number of days in month m of year y
    - use the private method is_leap_year() to check if the year is a leap year
    - if m is 2, return 29 if y is a leap year, otherwise return 28
    - if m is 4, 6, 9, or 11, return 30
    - otherwise return 31
    ***********************************************/
   return 0; // DELETE/REPLACE this line when done
}

bool Date::is_leap_year(int y) {
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        return true;
    }
    return false;
}

void Date::add_one_day() {
    /***********************************************
     TODO: add one day to the date
     - increment the day by 1   
     - call days_in_month() to check if the day 
     exceeds the number of days in the month,year
     - if it does, reset the day to 1 and increment
     the month by 1, subsequently check if the month
     exceeds 12, if yes reset the month to 1 and 
     increment the year by 1
    ***********************************************/
}

// print the date in the format mm/dd/yyyy
void Date::print() {
    /***********************************************
    TODO: print the date in the format mm/dd/yyyy
    ***********************************************/
}

// add n days to the date
void Date::add_days(int n) {
    /***********************************************
    TODO: add n days to the date (n>=0)
    - throw exception if n<0
    - here you can implement a loop to add all days 
    one by one, calling a private helper method 
    add_one_day() 
    - it is less efficient but easier to understand
    and implement
    ************************************************/
}

// overload the += operator to add n days to the date
Date& Date::operator+=(int n) {
    /***********************************************
    TODO: 
    - throw exception if n<0
    - call add_days() to add n days to the date
    ***********************************************/

    // returns a reference to the current object
    return *this; 
}

// overload the == operator to compare two dates
bool Date::operator==(const Date& d) {
    /***********************************************
    TODO:
    - return true if the current date and the date
    passed as parameter are equal, otherwise return false 
    ***********************************************/
    return false;
}

// overload the != operator to compare two dates
bool Date::operator!=(const Date& d) {
    /***********************************************
    TODO:
    - return true if the current date and the date
    passed as parameter are not equal, otherwise return false
    ***********************************************/
    return false;
}

// overload the < operator to compare two dates
bool Date::operator<(const Date& d) {
    /***********************************************
    TODO:
    - return true if the current date is less than the date passed as parameter, otherwise return false
    ***********************************************/
    return false;
}