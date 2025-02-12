#ifndef DATE_H
#define DATE_H

class Date {
    private: // private data members         
        int day;
        int month;
        int year;

    public: // public member functions
        // constructors and destructor
        Date();
        Date(int d, int m, int y);
        ~Date();
        // private methods
        bool is_valid_date(int d, int m, int y);
        int days_in_month(int m, int y);
        bool is_leap_year(int y);
        void add_one_day();
        // public methods
        void print();
        void add_days(int n);
        // overloaded operators
        Date& operator+=(int n);
        bool operator==(const Date& d);
        bool operator!=(const Date& d);
        bool operator<(const Date& d);
};

#endif