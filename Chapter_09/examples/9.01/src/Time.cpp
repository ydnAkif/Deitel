#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.hpp"

Time::Time()
    : hour(0), minute(0), second(0)
{
}

Time::~Time() {}

void Time::setTime(int h, int m, int s)
{
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
    {
        hour = h;
        minute = m;
        second = s;
    }
    else
    {
        throw std::invalid_argument(
            "hour, Minute and/or second was out of range");
    }
}

void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setfill('0') << std::setw(2) << second;
}

void Time::printStandart() const
{
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setw(2) << second << (hour < 12 ? " AM" : " PM");
}
