#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "Time.hpp"

Time::Time()
{
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);

    localTime = localtime(&currentTime);
    hour = localTime->tm_hour;
    minute = localTime->tm_min;
    second = localTime->tm_sec;
}

Time::Time(int hour, int minute, int second)
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
        hour = h;
    else
        throw std::invalid_argument("hour must be 0-23");
}

void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw std::invalid_argument("minute must be 0-59");
}

void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw std::invalid_argument("second must be 0-59");
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":" << std::setw(2)
              << getSecond();
}

void Time::printStandard() const
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}
