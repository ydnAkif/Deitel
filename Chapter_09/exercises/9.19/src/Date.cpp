#include <iostream>
#include <array>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Date.hpp"

const std::array<int, Date::monthsPerYear + 1> Date::daysPerMonth = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const std::array<std::string, Date::monthsPerYear + 1> Date::monthsNames = {
    "unknown", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

Date::Date(int mn, int dy, int yr)
{
    if ((mn > 0 && mn <= monthsPerYear))
    {
        month = mn;
    }
    else
    {
        throw std::invalid_argument("mont must be 1-12");
    }

    year = yr;
    day = chechDay(dy);

    std::cout << "Date object constructor for date ";
    print();
    std::cout << std::endl;
}

Date::Date(std::string dateString) : month(0), day(0), year(0)
{
    if (dateString.find(",") != std::string::npos)
    {
        size_t pos_first_space = dateString.find(" ");

        if (pos_first_space == std::string::npos)
        {
            throw("Invalid date string.");
        }
        else
        {
            try
            {
                std::string monthString = dateString.substr(0, pos_first_space);
                month = getMonthFromString(monthString);
                size_t pos_comma = dateString.find(",");
                std::string dayString = dateString.substr(pos_first_space + 1, pos_comma - pos_first_space - 1);
                day = std::stoi(dayString);
                std::string yearString = dateString.substr(pos_comma + 2, dateString.length() - pos_comma);
                year = std::stoi(yearString);
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    else if (dateString.find(" ") != std::string::npos) // DDD YYYY
    {
        size_t pos_space = dateString.find(" ");
        std::string dayOfYearString = dateString.substr(0, pos_space);
        int DDD = std::stoi(dayOfYearString);
        std::string yearString = dateString.substr(pos_space + 1, dateString.length() - pos_space - 1);
        year = std::stoi(yearString);

        month = 0;

        for (int i = 0; i <= daysPerMonth.size() - 1; ++i)
        {
            if (DDD <= daysPerMonth[i])
            {
                month = i;
                day = DDD;
                break;
            }

            DDD -= daysPerMonth[i];
        }
    }
    else if (dateString.find("/") != std::string::npos)
    {
        std::vector<std::string> strings;
        std::istringstream f(dateString);
        std::string s;

        while (std::getline(f, s, '/'))
        {
            strings.push_back(s);
        }

        std::string monthString = strings.at(0);
        month = std::stoi(monthString);
        std::string dayString = strings.at(1);
        day = std::stoi(dayString);
        std::string yearString = strings.at(2);
        year = std::stoi(yearString);
    }
    else
    {
        throw("Invalid input string.");
    }

    if (month > 0 && month <= monthsPerYear)
    {
        month = month;
    }
    else
    {
        throw std::invalid_argument("month must be 1-12.");
    }

    day = chechDay(day);
    std::cout << "Date object constructor for date ";
    print();
    std::cout << std::endl;
}

Date::Date(time_t time) : day(0), month(0), year(0)
{

    struct tm strTm;
    errno_t en = ::localtime_s(&strTm, &time);

    if (en == EINVAL)
    {
        throw("Invalid ctime input");
    }
    day = strTm.tm_mday;
    month = strTm.tm_mon + 1;
    year = strTm.tm_year + 1900;

    if (month > 0 && month <= monthsPerYear)
    {
        month = month;
    }
    else
    {
        throw std::invalid_argument("month must be 1-12.");
    }

    day = chechDay(day);
    std::cout << "Date object constructor for date ";
    print();
    std::cout << std::endl;
}

Date::~Date()
{
    std::cout << "Date object deconstructor for date ";
    print();
    std::cout << std::endl;
}

void Date::print() const
{
    std::cout << month << '/' << day << '/' << year;
}

void Date::printDDD_YYYY() const
{
    int ddd = 0;
    for (unsigned int i = 1; i <= month - 1; ++i)
    {
        ddd += daysPerMonth[i];
    }

    ddd += day;
    std::setfill('0');
    std::cout << std::setw(3) << ddd << " " << year << std::endl;
}

void Date::printMM_DD_YY() const
{
    int YY = year % 100;
    int MM = month;
    int DD = day;

    std::cout << MM << "/" << DD << "/" << YY << std::endl;
}

void Date::printEn_US() const
{
    std::string monthString;
    switch (month)
    {
    case 1:
        monthString = monthsNames[1];
        break;
    case 2:
        monthString = monthsNames[2];
        break;
    case 3:
        monthString = monthsNames[3];
        break;
    case 4:
        monthString = monthsNames[4];
        break;
    case 5:
        monthString = monthsNames[5];
        break;
    case 6:
        monthString = monthsNames[6];
        break;
    case 7:
        monthString = monthsNames[7];
        break;
    case 8:
        monthString = monthsNames[8];
        break;
    case 9:
        monthString = monthsNames[9];
        break;
    case 10:
        monthString = monthsNames[10];
        break;
    case 11:
        monthString = monthsNames[11];
        break;
    case 12:
        monthString = monthsNames[12];
        break;
    default:
        monthString = monthsNames[0];
        break;
    }

    std::cout << monthString << " " << day << ", " << year << std::endl;
}

int Date::getMonthFromString(std::string monthString) const
{
    for (int i = 0; i < static_cast<int>(monthsNames.size()); ++i)
    {
        if (monthString == monthsNames.at(i))
        {
            return i;
        }
    }
    return 1;
}

unsigned int Date::chechDay(int testDay) const
{

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    //February 29 check for leap year
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw std::invalid_argument("Invalid day for current month and year");
}
