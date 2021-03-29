#ifndef DATE_HPP
#define DATE_HPP

#include <array>
#include <iostream>

class Date
{
    friend std::ostream &operator<<(std::ostream &, const Date &);

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    static const std::array<unsigned int, 13> days;
    void helpIncrement();

public:
    Date(int = 1, int = 1, int = 1900);
    void setDate(int, int, int);
    Date &operator++();
    Date operator++(int);
    Date &operator+=(unsigned int);
    static bool leapYear(int);
    bool endOfMonth(int) const;
};

#endif