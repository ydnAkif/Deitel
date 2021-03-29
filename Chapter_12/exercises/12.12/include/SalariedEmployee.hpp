#ifndef SALARIED_EMPLOYEE_HPP
#define SALARIED_EMPLOYEE_HPP

#include <string>       // C++ standard string class
#include "Employee.hpp" // Employee class definition

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string &, const std::string &,
                     const std::string &, int, int, int, double = 0.0);
    virtual ~SalariedEmployee() = default; // virtual destructor

    void setWeeklySalary(double);   // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // keyword virtual signals intent to override
    virtual double earnings() const override;      // calculate earnings
    virtual void print() const override; // string representation
private:
    double weeklySalary; // salary per week
};

#endif