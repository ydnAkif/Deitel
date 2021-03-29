#include <iostream>
#include <iomanip>
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"

int main(int argc, char const *argv[])
{
    CommissionEmployee commissionEmployee{
        "Sue", "Jones", "222-22-2222", 10000, .06};

    // create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee{
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300};

    std::cout << std::fixed << std::setprecision(2); // set floating-point formatting

    // output objects commissionEmployee and basePlusCommissionEmployee
    std::cout << "DISPLAY BASE-CLASS AND DERIVED-CLASS OBJECTS:\n"
              << commissionEmployee.toString() // base-class toString
              << "\n\n"
              << basePlusCommissionEmployee.toString(); // derived-class toString

    // natural: aim base-class pointer at base-class object
    CommissionEmployee *commissionEmployeePtr{&commissionEmployee};
    std::cout << "\n\nCALLING TOSTRING WITH BASE-CLASS POINTER TO "
              << "\nBASE-CLASS OBJECT INVOKES BASE-CLASS TOSTRING FUNCTION:\n"
              << commissionEmployeePtr->toString(); // base version

    // natural: aim derived-class pointer at derived-class object
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr{
        &basePlusCommissionEmployee}; // natural
    std::cout << "\n\nCALLING TOSTRING WITH DERIVED-CLASS POINTER TO "
              << "\nDERIVED-CLASS OBJECT INVOKES DERIVED-CLASS "
              << "TOSTRING FUNCTION:\n"
              << basePlusCommissionEmployeePtr->toString(); // derived version

    // aim base-class pointer at derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\nCALLING TOSTRING WITH BASE-CLASS POINTER TO "
              << "DERIVED-CLASS OBJECT\nINVOKES BASE-CLASS TOSTRING "
              << "FUNCTION ON THAT DERIVED-CLASS OBJECT:\n"
              << commissionEmployeePtr->toString() // base version
              << std::endl;

    return 0;
}
