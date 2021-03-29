#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CommissionEmployee.hpp" // CommissionEmployee class definition
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string &first,
                                       const string &last, const string &ssn, int month, int day, int year,
                                       double sales, double rate)
    : Employee(first, last, ssn, month, day, year)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    if (sales < 0.0)
    {
        throw invalid_argument("Gross sales must be >= 0.0");
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
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
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
    cout << fixed << setprecision(2);
    cout << "commission employee: ";
    Employee::print();
    cout << "\ngross sales: " << getGrossSales()
         << "; commission rate: " << getCommissionRate();
}