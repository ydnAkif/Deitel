
#include <string>
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"

int main(int argc, char const *argv[])
{
   BasePlusCommissionEmployee basePlusCommissionEmployee{
       "Bob", "Lewis", "333-33-3333", 5000, .04, 300};

   // aim base-class pointer at derived-class object (allowed)
   CommissionEmployee *commissionEmployeePtr{&basePlusCommissionEmployee};

   // invoke base-class member functions on derived-class
   // object through base-class pointer (allowed)
   std::string firstName{commissionEmployeePtr->getFirstName()};
   std::string lastName{commissionEmployeePtr->getLastName()};
   std::string ssn{commissionEmployeePtr->getSocialSecurityNumber()};
   double grossSales{commissionEmployeePtr->getGrossSales()};
   double commissionRate{commissionEmployeePtr->getCommissionRate()};

   // attempt to invoke derived-class-only member functions
   // on derived-class object through base-class pointer (disallowed)
   double baseSalary{commissionEmployeePtr->getBaseSalary()};
   commissionEmployeePtr->setBaseSalary(500);

   return 0;
}
