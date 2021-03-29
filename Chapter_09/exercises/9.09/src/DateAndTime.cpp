#include <iostream>
#include <iomanip>
#include "DateAndTime.hpp"

DateAndTime::DateAndTime(int dy, int mo, int yr, int hr, int min, int sec)
{
    setDate(dy, mo, yr);
    setTime(hr, min, sec);
}

void DateAndTime::setDate(int d, int m, int y)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

void DateAndTime::setDay(int d)
{
    if (month == 2 && leapYear())
        day = (d <= 29 && d >= 1) ? d : 1;
    else
        day = (d <= monthDays() && d >= 1) ? d : 1;
}

void DateAndTime::setMonth(int m)
{
    month = (m <= 12 && m >= 1) ? m : 1;
}

void DateAndTime::setYear(int y)
{
    year = (y <= 2030 && y >= 2000) ? y : 2000;
}

void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void DateAndTime::setHour(int h)
{
    hour = (h < 24 && h >= 0) ? h : 0;
}

void DateAndTime::setMinute(int m)
{
    minute = (m < 60 && m >= 0) ? m : 0;
}

void DateAndTime::setSecond(int s)
{
    second = (s < 60 && s >= 0) ? s : 0;
}

int DateAndTime::getDay() const
{
    return day;
}

int DateAndTime::getMonth() const
{
    return month;
}

int DateAndTime::getYear() const
{
    return year;
}

int DateAndTime::getHour() const
{
    return hour;
}

int DateAndTime::getMinute() const
{
    return minute;
}

int DateAndTime::getSecond() const
{
    return second;
}

bool DateAndTime::leapYear() const
{
    if (getYear() % 400 == 0 || (getYear() % 4 == 0 && getYear() % 100 != 0))
        return true;
    else
        return false;
}

void DateAndTime::nextDay()
{
    setDay(getDay() + 1);
    if (getDay() == 1)
    {
        setMonth(getMonth() + 1);
        if (getMonth() == 1)
            setYear(getYear() + 1);
    }
}

int DateAndTime::monthDays()
{
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2 && leapYear()) ? 29 : days[month - 1];
}

void DateAndTime::tick()
{
    setSecond(getSecond() + 1);

    if (second == 0)
    {
        setMinute(getMinute() + 1);

        if (getMinute() == 0)
        {
            setHour(getHour() + 1);

            if (getHour() == 0)
                nextDay();
        }
    }
}

void DateAndTime::printStandard() const
{
    std::cout << std::setfill('0') << std::setw(2) << ((getHour() % 12 == 0) ? 12 : getHour()) % 12 << ':'
              << std::setw(2)
              << getMinute() << ':'
              << std::setw(2)
              << getSecond()
              << ((getHour() < 12) ? " AM " : " PM ")
              << std::setw(2) << getDay() << '/'
              << std::setw(2) << getMonth() << '/'
              << std::setw(4) << getYear() << std::endl;
}

void DateAndTime::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ':'
              << std::setw(2) << getMinute() << ':'
              << std::setw(2) << getSecond()
              << " "
              << std::setw(2) << getDay() << '/'
              << std::setw(2) << getMonth() << '/'
              << std::setw(4) << getYear() << std::endl;
}