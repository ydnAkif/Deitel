#include <iostream>
#include <stdexcept>
#include <sstream>
#include "BasePlusCommissionEmployee.hpp"

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const std::string &first, const std::string &last, const std::string &ssn,
    double sales, double rate, double salary)
    // explicitly call base-class constructor
    : ce(first, last, ssn, sales, rate)
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

// calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
   return ce.getCommissionRate() * ce.getGrossSales() + getBaseSalary();
}

// return string representation of BasePlusCommissionEmployee object
std::string BasePlusCommissionEmployee::toString() const
{
   std::ostringstream output;
   output << "base-salaried " << ce.toString()
          << "\nbase salary: " << getBaseSalary();
   return output.str();
}
