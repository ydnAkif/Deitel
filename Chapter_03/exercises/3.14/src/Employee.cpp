#include "Employee.hpp"

using namespace std;

Employee::Employee(std::string fName,
                   std::string lName, int mSalary)
{
    setFirstName(fName);
    setLastName(lName);
    setMonthlySalary(mSalary);
}

// Setters

void Employee::setFirstName(string fName)
{
    firstName = fName;
}
void Employee::setLastName(string lName)
{
    lastName = lName;
}

void Employee::setMonthlySalary(int mSalary)
{
    monthlySalary = (mSalary > 0) ? mSalary : 0;
}

// Getters

std::string Employee::getFirstName() const
{
    return firstName;
}

std::string Employee::getLastName() const
{
    return lastName;
}

int Employee::getMonthlySalary() const
{
    return monthlySalary;
}

int Employee::calculateSalary(int months) const
{
    return (getMonthlySalary() * months);
}

void Employee::giveRaise(int percent)
{
    monthlySalary += (monthlySalary / 100) * percent;
}

void Employee::showEmployees() const
{
    std::cout << "Name          : "
              << getFirstName()
              << std::endl;

    std::cout << "LastName      : "
              << getLastName()
              << std::endl;

    std::cout << "Montly Salary : "
              << getMonthlySalary()
              << std::endl;

    std::cout << "Yearly Salary : "
              << calculateSalary(12)
              << std::endl;

    std::cout << std::endl;
}