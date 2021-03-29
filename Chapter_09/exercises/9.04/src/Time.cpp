#include <ctime>
#include <iomanip>
#include <iostream>
#include "Time.hpp"

Time::Time()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    setHour(timeinfo->tm_hour);
    setMinute(timeinfo->tm_min);
    setSecond(timeinfo->tm_sec);
}

Time::~Time() {}

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

void Time::printStandard() const
{
    std::cout << std::setfill('0') << std::setw(2)
              << ((getHour() % 12 == 0) ? 12 : getHour() % 12) << ":"
              << std::setw(2)
              << getMinute() << ":"
              << std::setw(2)
              << getSecond() << (hour < 12 ? " AM" : " PM");
}

void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2)
              << getHour() << ":"
              << std::setw(2)
              << getMinute() << ":" << std::setw(2)
              << getSecond();
}