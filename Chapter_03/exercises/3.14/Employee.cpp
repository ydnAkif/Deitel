#include "Employee.hpp"

using namespace std;

Employee::Employee(string fName, string lName, int mSalary)
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

string Employee::getFirstName() const
{
    return firstName;
}

string Employee::getLastName() const
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
    cout << "Name          : " << getFirstName() << endl;
    cout << "LastName      : " << getLastName() << endl;
    cout << "Montly Salary : " << getMonthlySalary() << endl;
    cout << "Yearly Salary : " << calculateSalary(12) << endl;
    cout << endl;
}