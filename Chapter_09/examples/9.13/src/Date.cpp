#include <iostream>
#include "Date.hpp"

Date::Date(int d, int m, int y)
    : day(d), month(m), year(y)
{
}

Date::~Date()
{
}

void Date::print()
{
    std::cout << day << "/" << month << "/" << year;
}