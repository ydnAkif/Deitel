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
                   int, int, int, double = 0.0, double = 0.0);
    virtual ~HourlyEmployee() = default;

    void setWage(double);
    double getWage() const;

    void setHours(double);
    double getHours() const;

    virtual double earnings() const;
    virtual void print() const;
};

#endif