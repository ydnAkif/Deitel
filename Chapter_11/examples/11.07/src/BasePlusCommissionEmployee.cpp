#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.hpp"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string &first,
                                                       const std::string &last, const std::string &ssn,
                                                       double sales, double rate, double salary)
{
    setFirstName(first);
    setLastName(last);
    setSocialSecurityNumber(ssn);
    setGrossSales(sales);
    setCommissionRate(rate);
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setFirstName(const std::string &first)
{
    firstName = first;
}

std::string BasePlusCommissionEmployee::getFirstName() const
{
    return firstName;
}

void BasePlusCommissionEmployee::setLastName(const std::string &last)
{
    lastName = last;
}

std::string BasePlusCommissionEmployee::getLastName() const
{
    return lastName;
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string &ssn)
{
    socialSecurityNumber = ssn;
}

std::string BasePlusCommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void BasePlusCommissionEmployee::setGrossSales(double sales)
{
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw std::invalid_argument("Gross sales must be >= 0.0");
}

double BasePlusCommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void BasePlusCommissionEmployee::setCommissionRate(double rate)
{
    if (rate >= 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw std::invalid_argument("Commission rate must be >=0.0 and < 1.0");
}

double BasePlusCommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if (salary >= 0)
        baseSalary = salary;
    else
        throw std::invalid_argument("Salary must be >= 0.0");
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
    return (getBaseSalary() + (getGrossSales() * getCommissionRate()));
}

void BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried commission employee: " << getFirstName() << ' ' << getLastName()
              << "\nsocial security number: " << getSocialSecurityNumber()
              << "\ngross sales: " << getGrossSales()
              << "\ncommission rate: " << getCommissionRate()
              << "\nbase salary: " << getBaseSalary();
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
}
