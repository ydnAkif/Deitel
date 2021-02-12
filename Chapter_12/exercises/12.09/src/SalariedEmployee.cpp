#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "SalariedEmployee.hpp" // SalariedEmployee class definition
using namespace std;

// constructor
SalariedEmployee::SalariedEmployee(const string &first,
                                   const string &last, const string &ssn, int month, int day, int year, double salary)
    : Employee(first, last, ssn, month, day, year)
{
    setWeeklySalary(salary);
}

// set salary
void SalariedEmployee::setWeeklySalary(double salary)
{
    if (salary < 0.0)
    {
        throw invalid_argument("Weekly salary must be >= 0.0");
    }

    weeklySalary = salary;
}

// return salary
double SalariedEmployee::getWeeklySalary() const { return weeklySalary; }

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const { return getWeeklySalary(); }

// return a string representation of SalariedEmployee's information
void SalariedEmployee::print() const
{

    std::cout << "salaried employee: ";
    Employee::print(); // reuse abstract base-class function
    std::cout << "\nweekly salary: " << getWeeklySalary();
}
