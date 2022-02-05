/******************************************************************************

    Exercises 3.15

    (Date Class) Create a class called Date that includes three pieces of
    information as data members a month (type int), a day (type int) and a year
    (type int). Your class should have a con- structor with three parameters that
    uses the parameters to initialize the three data members. For the purpose of
    this exercise, assume that the values provided for the year and day are correct,
     but ensure that the month value is in the range 1–12; if it isn’t, set the month
    to 1. Provide a set and a get func- tion for each data member. Provide a member
    function displayDate that displays the month, day and year separated by forward
    slashes (/). Write a test program that demonstrates class Date’s capabilities.

******************************************************************************/

#include <iostream>
#include "Date.hpp"

int main()
{

    Date date1(12, 7, 1983);
    Date date2(23, 6, 1984);

    date1.displayDate();
    date2.displayDate();
    return 0;
}