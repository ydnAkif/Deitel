#include <iostream>
#include <string>
#include "Date.hpp"

const std::array<int, 13> Date::days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int m, int d, int y)

{
    setDate(m, d, y);
}

void Date::setDate(int mm, int dd, int yy)
{
    month = (mm > 1 && mm <= 12) ? mm : 1;
    year = (yy >= 1900 && yy <= 2100) ? yy : 1990;

    if (month == 2 && leapYear(year))
        day = (dd >= 1 && dd <= 29) ? dd : 1;
    else
        day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}

Date &Date::operator++()
{
    helpIncrement();
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    helpIncrement();

    return temp;
}

const Date &Date::operator+=(int additionalDays)
{
    for (int i = 0; i < additionalDays; ++i)
        helpIncrement();
    return *this;
}

bool Date::leapYear(int testYear) const
{
    if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
        return true;
    else
        return false;
}

int Date::getMonth() const
{
    return month;
}

bool Date::endOfMonth(int testDay) const
{
    if (month == 2 && leapYear(year))
        return testDay == 29;
    else
        return testDay == days[month];
}

void Date::helpIncrement()
{
    if (!endOfMonth(day))
        day++;
    else
    {
        if (month < 12)
        {
            month++;
            day = 1;
        }
        else
        {
            year++;
            month = 1;
            day = 1;
        }
    }
}

std::ostream &operator<<(std::ostream &output, const Date &d)
{
    static std::string monthName[13] = {"", "January", "February",
                                        "March", "April", "May", "June", "July", "August",
                                        "September", "October", "November", "December"};
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;

    return output;
}

Date::~Date() {}