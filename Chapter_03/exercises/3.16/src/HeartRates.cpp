#include <iostream>
#include "HeartRates.hpp"

HeartRates::HeartRates(std::string fName,
                       std::string lName,
                       int d, int m, int y)
{
    setFirstName(fName);
    setLastName(lName);
    setDay(d);
    setBirthDay(d, m, y);
}

//Setters

void HeartRates::setFirstName(std::string fName)
{
    firstName = (fName.length() > 0) ? fName : "Firstname";
}

void HeartRates::setLastName(std::string lName)
{
    lastName = (lName.length() > 0) ? lName : "LastName";
}

void HeartRates::setBirthDay(int d, int m, int y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
    setAge();
}

void HeartRates::setDay(int d)
{
    day = (d > 0 && d <= 31) ? d : 1;
}

void HeartRates::setMonth(int m)
{
    month = (m <= 12 && m > 0) ? m : 1;
}

void HeartRates::setYear(int y)
{
    year = y;
}

void HeartRates::setAge()
{
    ageOfYears = getAge();
}

//Getters

std::string HeartRates::getFirstName() const
{
    return firstName;
}

std::string HeartRates::getLastName() const
{
    return lastName;
}

int HeartRates::getDay() const
{
    return day;
}

int HeartRates::getMonth() const
{
    return month;
}

int HeartRates::getYear() const
{
    return year;
}

int HeartRates::getAge() const
{
    if (ageOfYears > 0)
    {
        return ageOfYears;
    }

    int cDay, cMonth, cYear;
    std::cout << "Enter the current Date ( dd mm yyyy): ";
    std::cin >> cDay >> cMonth >> cYear;

    if (cMonth < getMonth())
    {
        return (cYear - getYear()) - 1;
    }
    else if (cMonth > getMonth())
    {
        return (cYear - getYear());
    }
    else
    {
        return ((cDay < getDay()) ? ((cYear - getYear()) - 1) : ((cYear - getYear())));
    }
}

int HeartRates::getMaxiumumHeartRate() const
{
    return 220 - getAge();
}

void HeartRates::getTargetHeartRate() const
{
    std::cout << "Your Target Heart Rate : "
              << 0.5 * getMaxiumumHeartRate()
              << " - "
              << 0.85 * getMaxiumumHeartRate()
              << std::endl;
}

void HeartRates::displayInformation() const
{
    std::cout << "\nFirst Name             : "
              << getFirstName()
              << std::endl;

    std::cout << "Last Name              : "
              << getLastName()
              << std::endl;

    std::cout << "Birthday               : "
              << getDay()
              << "/" << getMonth()
              << "/" << getYear()
              << std::endl;

    std::cout << "Age                    : "
              << getAge()
              << std::endl;

    std::cout << "Maximum Heart Rate     : "
              << getMaxiumumHeartRate()
              << std::endl;

    getTargetHeartRate();
}