#ifndef DATE_HPP
#define DATE_HPP

class Date
{
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

public:
    explicit Date(int = 1, int = 1, int = 2000);
    ~Date();
    void print();
};

#endif