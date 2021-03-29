#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_HPP
#define BASE_PLUS_COMMISSION_EMPLOYEE_HPP

#include <string>
#include "CommissionEmployee.hpp"

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
                               const std::string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;
    virtual double earnings() const override;
    virtual std::string toString() const override;
    ~BasePlusCommissionEmployee();
};

#endif