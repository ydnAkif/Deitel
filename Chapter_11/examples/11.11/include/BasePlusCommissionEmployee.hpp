#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_HPP
#define BASE_PLUS_COMMISSION_EMPLOYEE_HPP

#include <string>
#include "CommissionEmployee.hpp"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
                               const std::string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);   // set base salary
    double getBaseSalary() const; // return base salary

    double earnings() const;      // calculate earnings
    std::string toString() const; // create string representation
private:
    double baseSalary; // base salary
};

#endif