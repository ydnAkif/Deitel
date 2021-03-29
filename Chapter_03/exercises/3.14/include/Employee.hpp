
#include <string>
#include <iostream>

class Employee
{
private:
    std::string firstName;
    std::string lastName;
    int monthlySalary;

public:
    Employee(std::string, std::string, int);

    //Setters
    void setFirstName(std::string);
    void setLastName(std::string);
    void setMonthlySalary(int);

    //Getters

    std::string getFirstName() const;
    std::string getLastName() const;
    int getMonthlySalary() const;
    int calculateSalary(int) const;
    void giveRaise(int);
    void showEmployees() const;
};
