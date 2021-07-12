/******************************************************************************
 
 Exercises 3.14

 (Employee Class) Create a class called Employee that includes three pieces of 
 information as data members—a first name (type string), a last name 
 (type string) and a monthly salary (type int). [Note: In subsequent chapters, 
 we’ll use numbers that contain decimal points (e.g., 2.75)— called 
 floating-point values—to represent dollar amounts.] Your class should have a 
 constructor that initializes the three data members. Provide a set and a get 
 function for each data member. If the monthly salary is not positive, set it 
 to 0. Write a test program that demonstrates class Employee’s capabilities. 
 Create two Employee objects and display each object’s yearly salary. 
 Then give each Em- ployee a 10 percent raise and display each Employee’s 
 yearly salary again.

******************************************************************************/

#include <iostream>
#include "Employee.hpp"

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