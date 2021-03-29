#include <iostream>
#include "Employee.hpp"
#include "Date.hpp"

Employee::Employee(const std::string &first, const std::string &last,
                   const Date &dateOfBirth, const Date &dateOfHire)
    : firstName(first), lastName(last), birthDate(dateOfBirth), hireDate(dateOfHire)
{
    std::cout << "Employee object constructor: "
              << firstName << ' ' << lastName
              << std::endl;
}

void Employee::print() const
{
    std::cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    std::cout << " Birthday: ";
    birthDate.print();
    std::cout << std::endl;
}

Employee::~Employee()
{
    std::cout << "Employee object deconstructor: " << lastName << ", " << firstName << std::endl;
}