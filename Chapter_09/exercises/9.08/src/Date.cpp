#include <iostream>
#include <iomanip>
#include "Date.hpp"

Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

Date::~Date() {}

void Date::setDate(int dy, int mon, int yr)
{
    setDay(dy);
    setMonth(mon);
    setYear(yr);
}

void Date::setDay(int d)
{
    if (month == 2 && leapYear())
        day = (d <= 29 && d >= 1) ? d : 1;
    else
        day = (d <= monthDays() && d >= 1) ? d : 1;
}

void Date::setMonth(int m)
{
    month = m <= 12 && m >= 1 ? m : 1;
}

void Date::setYear(int y)
{
    year = y <= 2030 && y >= 2000 ? y : 2000;
}

int Date::getDay() const
{
    return day;
}
int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

bool Date::leapYear()
{
    if (getYear() % 400 == 0 || (getYear() % 4 == 0 && getYear() % 100 != 0))
        return true;
    else
        return false;
}

int Date::monthDays()
{
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return month == 2 && leapYear() ? 29 : days[month - 1];


}

void Date::nextDay()
{
    setDay(getDay() + 1);

    if (getDay() == 1)
    {
        setMonth(getMonth() + 1);

        if (getMonth() == 1)
            setYear(getYear() + 1);
    }
}

void Date::print() const
{
    std::cout << std::setfill('0') << std::setw(2) << day << "/"
              << std::setw(2) << month << "/" << std::setw(4) << year << std::endl;
}