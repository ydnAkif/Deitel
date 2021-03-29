#include <iostream>
#include <iomanip>
#include "HourlyEmployee.hpp"

HourlyEmployee::HourlyEmployee(const std::string &first,
                               const std::string &last, const std::string &ssn,
                               double hourlyWage, double hoursWorked)
    : Employee(first, last, ssn)
{
    setWage(hourlyWage);
    setHours(hoursWorked);
}

void HourlyEmployee::setWage(double hourlyWage)
{
    wage = (hourlyWage < 0.0) ? 0.0 : hourlyWage;
}

double HourlyEmployee::getWage() const
{
    return wage;
}

void HourlyEmployee::setHours(double hoursWorked)
{
    hours = ((hoursWorked >= 0.0) && (hoursWorked <= 168.0)) ? hoursWorked : 0.0;
}

double HourlyEmployee::getHours() const
{
    return hours;
}

double HourlyEmployee::earnings() const
{
    if (getHours() <= 40)
        return getWage() * getHours();
    else
        return 40 * getWage() + ((getHours() - 40) * getWage() * 1.5);
}

void HourlyEmployee::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "hourly employee: ";
    Employee::print();
    std::cout << "\nhourly wage: " << getWage()
              << "; hours worked: " << getHours();
}