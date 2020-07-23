#include <iostream>
#include <string>
#include "HealthProfile.hpp"

HealthProfile::HealthProfile(std::string fName, std::string lName,
                             std::string g, int d, int m, int y,
                             double h, double w)
{
    setFirstName(fName);
    setLastName(lName);
    setGender(g);
    setBirthday(d, m, y);

    setHeight(h);
    setWeight(w);

    setAge();
}

// SETTERS

void HealthProfile::setFirstName(std::string fName)
{
    firstName = (fName.length() > 0) ? fName : "First Name";
}

void HealthProfile::setLastName(std::string lName)
{
    lastName = (lName.length() > 0) ? lName : "Last Name";
}

void HealthProfile::setGender(std::string g)
{
    gender = (g == "Male" || g == "Female") ? g : "undefined";
}

void HealthProfile::setBirthday(int d, int m, int y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
}

void HealthProfile::setDay(int d)
{
    day = (d > 0 && d <= 31) ? d : 1;
}

void HealthProfile::setMonth(int m)
{
    month = (m > 0 && m <= 12) ? m : 1;
}

void HealthProfile::setYear(int y)
{
    year = y;
}

void HealthProfile::setAge()
{
    int cDay, cMonth, cYear;
    std::cout << "Enter the current date (dd mm yyyy): ";
    std::cin >> cDay >> cMonth >> cYear;

    if (cMonth < getMonth())
    {
        ageOfYear = (cYear - getYear()) - 1;
    }
    else if (cMonth > getMonth())
    {
        ageOfYear = cYear - getYear();
    }
    else
    {
        if (cDay < day)
        {
            ageOfYear = (cYear - getYear()) - 1;
        }
        else
        {
            ageOfYear = cYear - getYear();
        }
    }
}
void HealthProfile::setHeight(double h)
{
    height = h;
}
void HealthProfile::setWeight(double w)
{
    weight = w;
}

//Getters

std::string HealthProfile::getFirstName() const
{
    return firstName;
}

std::string HealthProfile::getLastName() const
{
    return lastName;
}

std::string HealthProfile::getGender() const
{
    return gender;
}

int HealthProfile::getDay() const
{
    return day;
}

int HealthProfile::getMonth() const
{
    return month;
}

int HealthProfile::getYear() const
{
    return year;
}

void HealthProfile::getBirthday() const
{
    std::cout << getDay()
              << "/"
              << getMonth()
              << "/"
              << getYear()
              << std::endl;
}

int HealthProfile::getAge()
{
    if (ageOfYear == 0)
    {
        setAge();
    }
    return ageOfYear;
}

double HealthProfile::getHeight() const
{
    return height;
}

double HealthProfile::getWeight() const
{
    return weight;
}

double HealthProfile::getBMI() const
{
    return (getWeight() / (getHeight() * getHeight())) * 10000;
}

int HealthProfile::getMaxHeartRate()
{
    return 220 - getAge();
}

void HealthProfile::getTargetHeartRate()
{
    std::cout << "Target Hearth Rate    : "
              << 0.5 * getMaxHeartRate()
              << " - "
              << 0.85 * getMaxHeartRate()
              << std::endl;
}

void HealthProfile::showHealthProfile()
{
    std::cout << "\nHealth Profile for "
              << getFirstName()
              << " "
              << getLastName()
              << std::endl
              << std::endl;

    std::cout << "Gender                : "
              << getGender()
              << std::endl;

    std::cout << "Birthday              : ";

    getBirthday();

    std::cout << "Age                   : "
              << getAge()
              << std::endl;

    std::cout << "BMI                   : "
              << getBMI()
              << std::endl;
    std::cout << "Max Heart Rate        : "
              << getMaxHeartRate()
              << std::endl;

    getTargetHeartRate();

    displayBMIInfo();
}

void HealthProfile::displayBMIInfo() const
{
    std::cout << "\nBMI VALUES"
              << std::endl;
    std::cout << "Underweight           : less than 18.5"
              << std::endl;
    std::cout << "Normal                : between 18.5 and 24.9"
              << std::endl;
    std::cout << "Overweight            : between 25 and 29.9"
              << std::endl;
    std::cout << "Obese                 : 30 or greater\n"
              << std::endl;
}