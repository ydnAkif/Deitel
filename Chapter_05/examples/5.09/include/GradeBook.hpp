#include <string>
#include <iostream>

class GradeBook
{
private:
    std::string courseName;
    int aCount;
    int bCount;
    int cCount;
    int dCount;
    int fCount;

public:
    explicit GradeBook(const std::string &);

    void setCourseName(const std::string &);

    std::string getCourseName() const;

    void displayMessage() const;
    void inputGrades() ;
    void displayGradeReport() const;
};
