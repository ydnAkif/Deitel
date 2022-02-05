#include "Date.hpp"

Date::Date()
{
    day = 1;
    month = 1;
    year = 1900;
}

Date::Date(const short d, const short m, const short y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
}

// Setters Definitions

void Date::setDay(const short d)
{
    this->day = (d > 0 && d <= 31) ? d : 1;
}

void Date::setMonth(const short m)
{
    this->month = (m > 0 && m <= 12) ? m : 1;
}

void Date::setYear(const short y)
{
    this->year = y;
}

// Getters Definitions

short Date::getDay() const
{
    return day;
}

short Date::getMonth() const
{
    return month;
}

short Date::getYear() const
{
    return year;
}

void Date::displayDate() const
{
    std::cout << this->day
              << "/"
              << this->month
              << "/"
              << this->year
              << std::endl;
}