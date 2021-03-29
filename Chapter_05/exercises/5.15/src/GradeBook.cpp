#include <iostream>
#include <iomanip>
#include "GradeBook.hpp"

GradeBook::GradeBook(std::string name)
{
    setCourseName(name);
    aCount = 0;
    bCount = 0;
    cCount = 0;
    dCount = 0;
    fCount = 0;
}

void GradeBook::setCourseName(std::string name)
{
    if (name.length() <= 25)
    {
        courseName = name;
    }
    else
    {
        courseName = name.substr(0, 25);
        std::cout << "Name \""
                  << name
                  << "\" exceeds maximum length (25)."
                  << std::endl
                  << "Limiting courseName to first 25 characters."
                  << std::endl
                  << std::endl;
    }
}

std::string GradeBook::getCourseName() const
{
    return courseName;
}

void GradeBook::displayMessage() const
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
    int grade;
    std::cout << "Enter the letter grades."
              << std::endl
              << "Enter the EOF character to end input." << std::endl;
    while ((grade = std::cin.get()) != EOF)
    {
        switch (grade)
        {
        case 'A':
        case 'a':
            ++aCount;
            break;
        case 'B':
        case 'b':
            ++bCount;
            break;
        case 'C':
        case 'c':
            ++cCount;
            break;
        case 'D':
        case 'd':
            ++dCount;
            break;
        case 'F':
        case 'f':
            ++fCount;
            break;
        case '\n':
        case '\t':
        case ' ':
            break;
        default:
            std::cout << "Incorrect letter grade entered."
                      << " Enter a new grade."
                      << std::endl;
            break;
        }
    }
}

void GradeBook::displayGradeReports() const
{
    std::cout << std::endl
              << std::endl
              << "Number of students who received each letter grade:"
              << std::endl
              << "A: "
              << aCount
              << std::endl
              << "B: "
              << bCount
              << std::endl
              << "C: "
              << cCount
              << std::endl
              << "D: "
              << dCount
              << std::endl
              << "F: "
              << fCount
              << std::endl;

    std::cout << "Grade Point Average: "
              << getAvarage()
              << std::fixed
              << std::setprecision(2)
              << std::endl;
}

double GradeBook::getAvarage() const
{
    int totalGrade = aCount * 4 + bCount * 3 + cCount * 2 + dCount * 1 + fCount * 0;
    int totalCount = aCount + bCount + cCount + dCount + fCount;
    return (static_cast<double>(totalGrade) / totalCount);
}