#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.hpp"

Time::Time(int hour, int minute, int second) : secondsSinceMidNight(0)

{
    setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
    {
        secondsSinceMidNight += h * 3600;
    }
    else
    {
        throw std::invalid_argument("hour must be 0-23");
    }
}

void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
    {
        secondsSinceMidNight += m * 60;
    }
    else
    {
        throw std::invalid_argument("minute must be 0-59");
    }
}

void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
    {
        secondsSinceMidNight += s;
    }
    else
    {
        throw std::invalid_argument("second must be 0-59");
    }
}

unsigned int Time::getHour() const
{
    return secondsSinceMidNight / 3600;
}

unsigned int Time::getMinute() const
{
    return secondsSinceMidNight % 3600 / 60;
}

unsigned int Time::getSecond() const
{
    return secondsSinceMidNight % 3600 % 60;
}

void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setfill('0') << std::setw(2) << getMinute() << ":"
              << std::setfill('0') << std::setw(2) << getSecond() << std::endl;
}

void Time::printStandart() const
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << std::endl;
}
