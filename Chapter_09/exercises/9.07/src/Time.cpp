#include <ctime>
#include <iomanip>
#include <iostream>
#include "Time.hpp"

Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

Time::~Time() {}

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

void Time::printStandard() const
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":" << std::setw(2)
              << getSecond();
}

void Time::tick()
{
    if (getSecond() < 59)
        setSecond(getSecond() + 1);
    else
    {
        setSecond(0);
        if (getMinute() < 59)
            setMinute(getMinute() + 1);
        else
        {
            setMinute(0);
            if (getHour() < 23)
                setHour(getHour() + 1);
            else
            {
                setHour(0);
                setMinute(0);
                setSecond(0);
            }
        }
    }
}