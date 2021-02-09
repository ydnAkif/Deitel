#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CommissionEmployee.hpp"
// constructor
CommissionEmployee::CommissionEmployee(const std::string &first,
                                       const std::string &last, const std::string &ssn, double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn)
{
    setGrossSales(sales);    // validate and store gross sales
    setCommissionRate(rate); // validate and store commission rate
}

// set first name
void CommissionEmployee::setFirstName(const std::string &first)
{
    firstName = first; // should validate
}

// return first name
std::string CommissionEmployee::getFirstName() const { return firstName; }

// set last name
void CommissionEmployee::setLastName(const std::string &last)
{
    lastName = last; // should validate
}

// return last name
std::string CommissionEmployee::getLastName() const { return lastName; }

// set social security number
void CommissionEmployee::setSocialSecurityNumber(const std::string &ssn)
{
    socialSecurityNumber = ssn; // should validate
}

// return social security number
std::string CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
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
    if (rate <= 0.0 || rate >= 1.0)
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

// calculate earnings
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

// return string representation of CommissionEmployee object
std::string CommissionEmployee::toString() const
{
    std::ostringstream output;
    output << std::fixed << std::setprecision(2); // two digits of precision
    output << "commission employee: " << getFirstName() << " " << getLastName()
           << "\nsocial security number: " << getSocialSecurityNumber()
           << "\ngross sales: " << getGrossSales()
           << "\ncommission rate: " << getCommissionRate();
    return output.str();
}