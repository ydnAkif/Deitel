#include <iostream>
#include <string>

#include "GradeBook.hpp"
using namespace std;
// Constructor
GradeBook::GradeBook(string name, string instructor)
{
   setCourseName(name);
   setInstructorName(instructor);
}
// SETTERS
void GradeBook::setCourseName(string name) { courseName = name; }
void GradeBook::setInstructorName(string instructor) { instructorName = instructor; }

// GETTERS
string GradeBook::getCourseName() const { return courseName; }
string GradeBook::getInstructorName() const { return instructorName; }

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   cout << "Welcome to the grade book for: " << getCourseName() << "!\n"
        << "This course is presented by: " << getInstructorName()
        << endl;
}
