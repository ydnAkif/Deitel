/******************************************************************************

Exercises 4.16

(Salary Calculator) Develop a C++ program that uses a while statement to 
determine the gross pay for each of several employees. The company pays “straight 
time” for the first 40 hours worked by each employee and pays “time-and-a-half” 
for all hours worked in excess of 40 hours. You are given a list of the employees 
of the company, the number of hours each employee worked last week and the hourly 
rate of each employee. Your program should input this information for each employee 
and should determine and display the employee’s gross pay.

******************************************************************************/

#include "SalaryCalculator.hpp"

static const int QUIT = -1;

int main(int argc, char const *argv[])
{
    SalaryCalculator sc;

    while (sc.getHourWorked() != QUIT)
    {
        sc.run();
    }

    return 0;
}
