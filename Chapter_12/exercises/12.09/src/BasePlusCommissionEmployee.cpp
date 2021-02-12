#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "BasePlusCommissionEmployee.hpp"

using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn, int month, int day, int year,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, month, day, year, sales, rate)
{
    setBaseSalary(salary); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if (salary < 0.0)
    {
        throw invalid_argument("Salary must be >= 0.0");
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
    cout << fixed << setprecision(2);
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "; base salary: " << getBaseSalary();
}