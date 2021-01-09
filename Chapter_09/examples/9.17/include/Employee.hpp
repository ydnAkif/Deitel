#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include "Date.hpp"

class Employee
{
private:
    std::string firstName;
    std::string lastName;
    const Date birthDate;
    const Date hireDate;

public:
    Employee(const std::string &, const std::string &, const Date &, const Date &);
    void print() const;
    ~Employee();
};

#endif