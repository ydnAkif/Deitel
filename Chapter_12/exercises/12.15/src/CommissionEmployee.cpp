#include <iomanip>
#include <stdexcept>
#include <iostream>
#include "CommissionEmployee.hpp" // CommissionEmployee class definition

// constructor
CommissionEmployee::CommissionEmployee(const std::string &first,
                                       const std::string &last, const std::string &ssn,
                                       double sales, double rate)
    : Employee(first, last, ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    if (sales < 0.0)
    {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }

    grossSales = sales;
}

// return gross sales amount
double CommissionEmployee::getGrossSales() const { return grossSales; }

// set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
    if (rate <= 0.0 || rate > 1.0)
    {
        throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }

    commissionRate = rate;
}

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

// return a string representation of CommissionEmployee's information
void CommissionEmployee::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "commission employee: ";
    Employee::print();
    std::cout << "\ngross sales: " << getGrossSales()
         << "; commission rate: " << getCommissionRate();
}