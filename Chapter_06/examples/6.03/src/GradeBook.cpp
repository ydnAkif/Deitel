#include <iostream>
#include "GradeBook.hpp"

GradeBook::GradeBook(std::string name)
{
    setCourseName(name);
    maximumGrade = 0;
}

void GradeBook::setCourseName(std::string name)
{

    if (name.size() <= 25)
    {
        courseName = name;
    }
    else
    {
        courseName = name.substr(0, 25);
        std::cerr << "Name \""
                  << name
                  << "\" exceeds maximum length (25)."
                  << std::endl
                  << "Limiting courseName to first 25 characters."
                  << std::endl
                  << std::endl;
    }
}

std::string GradeBook::getCourseName()
{
    return courseName;
}

void GradeBook::displayMessage()
{
    std::cout << "Welcome to the grade book for"
              << std::endl
              << getCourseName()
              << "!"
              << std::endl
              << std::endl;
}

void GradeBook::inputGrades()
{
    int grade1;
    int grade2;
    int grade3;

    std::cout << "Enter 3 integer grades: ";

    std::cin >> grade1 >> grade2 >> grade3;

    maximumGrade = maximum(grade1, grade2, grade3);
}

int GradeBook::maximum(int x, int y, int z)
{
    int maximumValue = x;
    if (y > maximumValue)
    {
        maximumValue = y;
    }
    if (z > maximumValue)
    {
        maximumValue = z;
    }

    return maximumValue;
}

void GradeBook::displayGradeReport()
{
    std::cout << "Maximum of grades entered : "
              << maximumGrade
              << std::endl;
}