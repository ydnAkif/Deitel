#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_HPP
#define BASE_PLUS_COMMISSION_EMPLOYEE_HPP

#include <string>                 // C++ standard string class
#include "CommissionEmployee.hpp" // CommissionEmployee class definition

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
                               const std::string &, double = 0.0, double = 0.0, double = 0.0);
    virtual ~BasePlusCommissionEmployee() = default; // virtual destructor

    void setBaseSalary(double);   // set base salary
    double getBaseSalary() const; // return base salary

    // keyword virtual signals intent to override
    virtual double earnings() const override;      // calculate earnings
    virtual std::string toString() const override; // string representation
private:
    double baseSalary; // base salary per week
};

#endif