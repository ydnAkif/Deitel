#include <iostream>
#include "Date.hpp"

Date::Date()
{
    day = 1;     // default day is 1
    month = 1;   // default month is 1
    year = 1900; // default year is 1900
}

Date::Date(const int d, const int m, const int y)
{
    setDay(d);   // set day
    setMonth(m); // set month
    setYear(y);  // set year
}

// Setters Definitions

void Date::setDay(const int d)
{
    this->day = d; // set day
}

void Date::setMonth(const int m)
{
    this->month = (m > 0 && m <= 12) ? m : 1; // if month is not valid, set it to 1
}

void Date::setYear(const int y)
{
    this->year = y; // set year
}

// Getters Definitions

int Date::getDay() const
{
    return day; // return day
}

int Date::getMonth() const
{
    return month; // return month
}

int Date::getYear() const
{
    return year; // return year
}

void Date::displayDate() const
{
    // display date in the format dd/mm/yyyy

    std::cout << this->day
              << "/"
              << this->month
              << "/"
              << this->year
              << std::endl;
}