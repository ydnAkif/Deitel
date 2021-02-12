#include <iomanip>
#include <stdexcept>
#include <iostream>
#include "BasePlusCommissionEmployee.hpp"


// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const std::string &first, const std::string &last, const std::string &ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if (salary < 0.0)
    {
        throw std::invalid_argument("Salary must be >= 0.0");
    }

    baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
}

// return a string representation of a BasePlusCommissionEmployee
void BasePlusCommissionEmployee::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "base-salaried ";
    CommissionEmployee::print();
    std::cout << "; base salary: " << getBaseSalary();
}