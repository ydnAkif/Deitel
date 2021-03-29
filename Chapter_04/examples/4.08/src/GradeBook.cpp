#include <iostream>
#include "GradeBook.hpp"

GradeBook::GradeBook(std::string name)
{
    setCourseName(name);
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
                  << "\" exceeds maximum length (25). \n"
                  << "Limiting courseName to first 25 characters.\n"
                  << std::endl;
    }
}

std::string GradeBook::getCourseName() const
{
    return courseName;
}

void GradeBook::displayMessage() const
{
    std::cout << "Welcome to the grade book for\n"
              << getCourseName()
              << "!\n"
              << std::endl;
}

void GradeBook::determineClassAvarage() const
{
    int total{0};
    unsigned int gradeCounter{1};
    while (gradeCounter <= 10)
    {
        std::cout << "Enter grade : ";
        int grade{0};
        std::cin >> grade;

        total += grade;
        ++gradeCounter;
    }

    int avarage{total / 10};

    std::cout << "\nTotal of all 10 grades is "
              << total
              << std::endl;

    std::cout << "Class average is "
              << avarage
              << std::endl;
}