#include <sstream>
#include "Employee.hpp" // Employee class definition
using namespace std;

// constructor
Employee::Employee(const string &first, const string &last,
                   const string &ssn, int month, int day, int year)
    : firstName(first), lastName(last), socialSecurityNumber(ssn),
      birthDate(month, day, year)
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

void Employee::setBirthDay(int month, int day, int year)
{
    birthDate.setDate(month, day, year);
}

Date Employee::getBirthDay() const
{
    return birthDate;
}

// toString Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
    std::cout << getFirstName() << " " << getLastName()
              << "\nbirthday: " << getBirthDay()
              << "\nsocial security number: " << getSocialSecurityNumber();
}
