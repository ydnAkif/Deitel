
#include <iomanip>
#include <iostream>
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"

int main(int argc, char const *argv[])
{
    // create base-class object
    CommissionEmployee commissionEmployee{
        "Sue", "Jones", "222-22-2222", 10000, .06};

    // create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee{
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300};

    std::cout << std::fixed << std::setprecision(2); // set floating-point formatting

    // output objects using static binding
    std::cout << "INVOKING TOSTRING FUNCTION ON BASE-CLASS AND DERIVED-CLASS "
              << "\nOBJECTS WITH STATIC BINDING\n"
              << commissionEmployee.toString() // static binding
              << "\n\n"
              << basePlusCommissionEmployee.toString(); // static binding

    // output objects using dynamic binding
    std::cout << "\n\nINVOKING TOSTRING FUNCTION ON BASE-CLASS AND "
              << "\nDERIVED-CLASS OBJECTS WITH DYNAMIC BINDING";

    // natural: aim base-class pointer at base-class object
    const CommissionEmployee *commissionEmployeePtr{&commissionEmployee};
    std::cout << "\n\nCALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER"
              << "\nTO BASE-CLASS OBJECT INVOKES BASE-CLASS "
              << "TOSTRING FUNCTION:\n"
              << commissionEmployeePtr->toString(); // base version

    // natural: aim derived-class pointer at derived-class object
    const BasePlusCommissionEmployee *basePlusCommissionEmployeePtr{
        &basePlusCommissionEmployee}; // natural
    std::cout << "\n\nCALLING VIRTUAL FUNCTION TOSTRING WITH DERIVED-CLASS "
              << "POINTER\nTO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS "
              << "TOSTRING FUNCTION:\n"
              << basePlusCommissionEmployeePtr->toString(); // derived version

    // aim base-class pointer at derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\nCALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER"
              << "\nTO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS "
              << "TOSTRING FUNCTION:\n";

    // polymorphism; invokes BasePlusCommissionEmployee's toString
    // via base-class pointer to derived-class object
    std::cout << commissionEmployeePtr->toString() << std::endl;

    return 0;
}
