#include "Date.hpp"

Date::Date(int d, int m, int y)
{

    setDays(d);
    setMonths(m);
    setYears(y);
}

// Setters

void Date::setDays(int d)
{
    days = d;
}

void Date::setMonths(int m)
{
    months = (m > 0 && m <= 12) ? m : 1;
}

void Date::setYears(int y)
{
    years = y;
}

//Getters

int Date::getDays() const
{
    return days;
}

int Date::getMonths() const
{
    return months;
}

int Date::getYears() const
{
    return years;
}

void Date::displayDate() const
{
    std::cout << getDays()
              << "/"
              << getMonths()
              << "/"
              << getYears()
              << std::endl;
}