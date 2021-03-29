#include <iostream>
#include <array>
#include <stdexcept>
#include "Date.hpp"

Date::Date(int dy, int mn, int yr)
{
    if ((mn > 0 && mn <= monthsPerYear))
    {
        month = mn;
    }
    else
    {
        throw std::invalid_argument("mont must be 1-12");
    }

    year = yr;
    day = chechDay(dy);

    std::cout << "Date object constructor for date ";
    print();
    std::cout << std::endl;
}

Date::~Date()
{
    std::cout << "Date object deconstructor for date ";
    print();
    std::cout << std::endl;
}

void Date::print() const
{
    std::cout << day << '/' << month << '/' << year;
}

unsigned int Date::chechDay(int testDay) const
{
    //0,Jan,Feb,Mar,Apr,Jun,Jul,Aug,Sep,Oct,Nov,Dec
    static const std::array<int, monthsPerYear + 1> daysPerMonth =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    //February 29 check for leap year
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw std::invalid_argument("Invalid day for current month and year");
}