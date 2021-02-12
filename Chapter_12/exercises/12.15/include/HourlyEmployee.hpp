#ifndef HOURLY_EMPLOYEE_HPP
#define HOURLY_EMPLOYEE_HPP

#include "Employee.hpp"

class HourlyEmployee : public Employee
{
private:
    double wage;
    double hours;

public:
    HourlyEmployee(const std::string &, const std::string &, const std::string &,
                   double = 0.0, double = 0.0);
    virtual ~HourlyEmployee(){};

    void setWage(double);
    double getWage() const;

    void setHours(double);
    double getHours() const;

    virtual double earnings() const override;
    virtual void print() const override;
};

#endif