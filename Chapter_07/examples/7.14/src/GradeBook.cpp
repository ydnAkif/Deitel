#include <iostream>
#include <iomanip>
#include "GradeBook.hpp"

GradeBook::GradeBook(const std::string &name,
                     const std::array<int, students> &gradesArray)
    : courseName(name), grades(gradesArray)
{
}

GradeBook::~GradeBook()
{
}

void GradeBook::setCourseName(const std::string &name)
{
    courseName = name;
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
              << std::endl;
}

void GradeBook::processGrades() const
{
    outputGrades();

    std::cout << std::setprecision(2)
              << std::fixed;
    std::cout << std::endl
              << "Class average is "
              << getAverage()
              << std::endl;
    std::cout << "Lowest grade is "
              << getMinimum()
              << std::endl
              << "Highest grade is "
              << getMaximum()
              << std::endl;
    outputBarChart();
}

int GradeBook::getMinimum() const
{
    int lowGrade = 100;
    for (int grade : grades)
    {
        if (grade < lowGrade)
            lowGrade = grade;
    }
    return lowGrade;
}

int GradeBook::getMaximum() const
{
    int highGrade = 0;
    for (int grade : grades)
    {
        if (grade > highGrade)
            highGrade = grade;
    }
    return highGrade;
}

double GradeBook::getAverage() const
{
    int total = 0;
    for (int grade : grades)
        total += grade;
    return static_cast<double>(total) / grades.size();
}

void GradeBook::outputBarChart() const
{
    std::cout << std::endl
              << "Grade distribution:"
              << std::endl;
    const size_t frequencySize = 11;
    std::array<int, frequencySize> frequency = {};
    for (int grade : grades)
        ++frequency[grade / 10];
    for (size_t count = 0; count < frequency.size(); ++count)
    {
        if (0 == count)
        {
            std::cout << "  0-9: ";
        }
        else if (10 == count)
        {
            std::cout << " 100: ";
        }
        else
        {
            std::cout << count * 10
                      << "-"
                      << (count * 10) + 9
                      << ": ";
        }

        for (unsigned int stars = 0; stars < frequency[count]; ++stars)
            std::cout << "*";
        std::cout << std::endl;
    }
}

void GradeBook::outputGrades() const
{
    std::cout << std::endl
              << "The grades are:"
              << std::endl
              << std::endl;
    for (size_t student = 0; student < grades.size(); ++student)
    {
        std::cout << "Student "
                  << std::setw(2)
                  << student + 1
                  << ": "
                  << std::setw(3)
                  << grades[student]
                  << std::endl;
    }
}