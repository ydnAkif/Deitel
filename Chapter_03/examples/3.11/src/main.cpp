/*
 * =====================================================================================
 *
 *       Filename:  fig03_11.cpp
 *
 *    Description:  Fig. 3.11: GradeBook class demonstration after separating
 *                  its interface from its implementation.
 *
 *        Version:  1.0
 *        Created:  20/03/16 19:47:43
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Akif AYDIN - akifaydin52@gmail.com
 *   
 *
 * =====================================================================================
 */
#include <iostream>
#include "GradeBook.hpp"

int main(int argc, const char *argv[])
{
    GradeBook gradeBook1("CS101 Introduction to C++ Programming.");
    GradeBook gradeBook2("CS102 Data Structures in C++.");

    // display initial values of courseName for each GradeBook
    std::cout << "gradeBook1 created for course: "
              << gradeBook1.getCourseName();
    std::cout << "\ngradeBook2 created for course: "
              << gradeBook2.getCourseName() << std::endl;
    return 0;
}
