#include "GradeBook.hpp"

int main()
{
    const std::array<int, GradeBook::students> grades =
        {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
    std::string courseName = "CS101 Introduction to C++ Programming";

    GradeBook myGradeBook(courseName, grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();

    return 0;
}
