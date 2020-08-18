/*
 * =====================================================================================
 *
 *       Filename:  fig03_05.cpp
 *
 *    Description:  Fig. 3.5: Define class GradeBook that contains a courseName
 *                  data member and member functions to set and get its value;
 *                  Create and manipulate a GradeBook object with theses
 *                  functions.
 *
 *        Version:  1.0
 *        Created:  11/03/16 23:45:32
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Akif AYDIN - akifaydin52@gmail.com
 *   
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

class GradeBook
{
private:
    std::string courseName;

public:
    // SETTERS
    void setCourseName(const std::string &name) { courseName = name; }
    // GETTERS
    std::string getCourseName() { return courseName; }
    // function that displays a welcome message
    void displayMessage()
    {
        // this statement calls getCourseName to get the name of the course
        // this GradeBook represents
        std::cout << "Welcome to the grade book for\n"
                  << getCourseName() << "!" << std::endl;
    }
};

// function main begins program execution
int main(int argc, const char *argv[])
{
    std::string nameOfCourse;
    GradeBook myGradeBook;

    // display initial value of courseName
    std::cout << "Initial course name is: " << myGradeBook.getCourseName()
              << std::endl;

    // prompt for input and set course name
    std::cout << "\nPlease enter the course name: " << std::endl;
    std::getline(std::cin, nameOfCourse);

    myGradeBook.setCourseName(nameOfCourse);

    std::cout << std::endl;

    myGradeBook.displayMessage();
    return 0;
}
