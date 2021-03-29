#include <iostream>
#include "GradeBook.hpp"

int main()
{
    GradeBook myGradeBook("C++ Programming");
    myGradeBook.displayMessage();
    myGradeBook.inputGrades();
    myGradeBook.displayGradeReports();

    return 0;
}