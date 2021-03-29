#include <iostream>
#include <iomanip>
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"

int main(int argc, char const *argv[])
{
    CommissionEmployee commissionEmployee{
        "Sue", "Jones", "222-22-2222", 10000, .06};

    BasePlusCommissionEmployee* basePlusCommissionEmployeePtr{
    &commissionEmployee};
    
    return 0;
}
