/*******************************************************************************

Exercises 3.11

(Modifying Class GradeBook) Modify class GradeBook (Figs. 3.11–3.12) as follows:
a) Include a second string data member that represents the course instructor’s
name.
b) Provideasetfunctiontochangetheinstructor’snameandagetfunctiontoretrieveit.
c) Modify the constructor to specify course name and instructor name parameters.
d) Modify function displayMessage to output the welcome message and course name,
then the string "This course is presented by: " followed by the instructor’s
name.

Use your modified class in a test program that demonstrates the class’s new 
capabilities.

*******************************************************************************/


#include "GradeBook.hpp"

int main()
{
    GradeBook gradeBook1("This is a course", "The Instructor");

    gradeBook1.displayMessage();

    system("pause");
    return 0;
}
