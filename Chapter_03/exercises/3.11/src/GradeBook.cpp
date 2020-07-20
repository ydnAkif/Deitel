#include <iostream>
#include "GradeBook.hpp"

// Constructor
GradeBook::GradeBook(std::string name, std::string instructor)
{
   setCourseName(name);
   setInstructorName(instructor);
}
// SETTERS
void GradeBook::setCourseName(std::string name) { courseName = name; }
void GradeBook::setInstructorName(std::string instructor) { instructorName = instructor; }

// GETTERS
std::string GradeBook::getCourseName() const { return courseName; }
std::string GradeBook::getInstructorName() const { return instructorName; }

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   std::cout << "Welcome to the grade book for: "
             << getCourseName()
             << "!\n"
             << "This course is presented by: "
             << getInstructorName()
             << std::endl;
}
