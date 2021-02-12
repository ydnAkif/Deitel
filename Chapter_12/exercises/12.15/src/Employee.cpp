#include <iostream>
#include "Employee.hpp" // Employee class definition
using namespace std;

// constructor
Employee::Employee(const string &first, const string &last,
                   const string &ssn)
    : firstName(first), lastName(last), socialSecurityNumber(ssn)
{
}

// set first name
void Employee::setFirstName(const string &first) { firstName = first; }

// return first name
string Employee::getFirstName() const { return firstName; }

// set last name
void Employee::setLastName(const string &last) { lastName = last; }

// return last name
string Employee::getLastName() const { return lastName; }

// set social security number
void Employee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn; // should validate
}

// return social security number
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

// toString Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
    std::cout << getFirstName() << " " << getLastName()
              << "\nsocial security number: " << getSocialSecurityNumber();
}
