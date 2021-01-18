#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.hpp"

Time::Time(int hour, int minute, int second)

{
    setTime(hour, minute, second);
}

Time::error_status Time::setTime(int h, int m, int s)
{
    if (eOk != setHour(h))
        return eInvalidHour;
    if (eOk != setMinute(m))
        return eInvalidMinute;
    if (eOk != setSecond(s))
        return eInvalidSecond;

    return eOk;
}

Time::error_status Time::setHour(int h)
{
    if (h >= 0 && h < 24)
    {
        hour = h;
        return eOk;
    }
    else
        return eInvalidHour;
}

Time::error_status Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
    {
        minute = m;
        return eOk;
    }
    else
        return eInvalidMinute;
}

Time::error_status Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
    {
        second = s;
        return eOk;
    }
    else
        return eInvalidSecond;
}

unsigned int Time::getHour() const
{
    return hour;
}

unsigned int Time::getMinute() const
{
    return minute;
}

unsigned int Time::getSecond() const
{
    return second;
}

void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setfill('0') << std::setw(2) << getMinute() << ":"
              << std::setfill('0') << std::setw(2) << getSecond();
}

void Time::printStandart() const
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

void Time::printSetError(Time::error_status es)
{
    switch (es)
    {
    case Time::eOk:
        break;
    case Time::eInvalidHour:
        std::cout << "Invalid Hour\n";
        setHour(0);
        break;
    case Time::eInvalidMinute:
        std::cout << "Invalid Minute\n";
        setMinute(0);
        break;
    case Time::eInvalidSecond:
        std::cout << "Invalid Second\n";
        setSecond(0);
        break;
    case Time::eInvalidTime:
        std::cout << "Invalid Time\n";
        setTime(0, 0, 0);
        break;
    default:
        std::cout << "Unknown Error\n";
        break;
    }
}