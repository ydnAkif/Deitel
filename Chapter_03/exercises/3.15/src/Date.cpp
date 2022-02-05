#include <iostream>
#include "Date.hpp"

Date::Date()
{
    day = 1;     // default day is 1
    month = 1;   // default month is 1
    year = 1900; // default year is 1900
}

Date::Date(const short d, const short m, const short y)
{
    setDay(d);   // set day
    setMonth(m); // set month
    setYear(y);  // set year
}

// Setters Definitions

void Date::setDay(const short d)
{
    this->day = (d > 0 && d <= 31) ? d : 1; // if day is not valid, set it to 1
}

void Date::setMonth(const short m)
{
    this->month = (m > 0 && m <= 12) ? m : 1; // if month is not valid, set it to 1
}

void Date::setYear(const short y)
{
    this->year = y; // set year
}

// Getters Definitions

short Date::getDay() const
{
    return day; // return day
}

short Date::getMonth() const
{
    return month; // return month
}

short Date::getYear() const
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