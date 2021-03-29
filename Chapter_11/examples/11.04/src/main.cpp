#include <iostream>
#include <iomanip>
#include "CommissionEmployee.hpp"

int main(int argc, char const *argv[])
{
    CommissionEmployee employee(
        "Sue", "Jones", "222-222-2222", 10000, .06);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Employee information obtained by get functions: \n"
              << "\nFirst name is " << employee.getFirstName()
              << "\nLast name is " << employee.getLastName()
              << "\nSocial security number is " << employee.getSocialSecurityNumber()
              << "\nGross sale is " << employee.getGrossSales()
              << "\nCommission rate is " << employee.getCommissionRate() << std::endl;
    employee.setGrossSales(8000);
    employee.setCommissionRate(.08);

    std::cout << "\nUpdated employee information output by print function: \n"
              << std::endl;
    employee.print();

    std::cout << "\n\nEmployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
}
