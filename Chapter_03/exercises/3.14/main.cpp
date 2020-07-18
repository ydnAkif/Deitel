#include <iostream>
#include "Employee.hpp"

using namespace std;

int main()
{
    Employee emp1("Akif", "AYDIN", 1200);
    Employee emp2("Aylin", "AYDIN", 2000);
    Employee emp3("Aysun", "AYDIN", 1500);

    emp1.showEmployees();
    emp2.showEmployees();
    emp3.showEmployees();

    emp1.giveRaise(10);
    emp2.giveRaise(8);
    emp3.giveRaise(12);

    emp1.showEmployees();
    emp2.showEmployees();
    emp3.showEmployees();

    return 0;
}