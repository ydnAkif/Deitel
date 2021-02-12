#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <array>

class Date
{
    friend std::ostream &operator<<(std::ostream &, const Date &);

private:
    int month;
    int day;
    int year;

    static const std::array<int, 13> days;
    void helpIncrement();

public:
    explicit Date(int = 1, int = 1, int = 1990);
    void setDate(int, int, int);
    Date &operator++();
    Date operator++(int);
    const Date &operator+=(int);
    bool leapYear(int) const;
    bool endOfMonth(int) const;
    int getMonth() const;
    ~Date();
};

#endif