#include <string>

class GradeBook
{
private:
    std::string courseName;
    int maximumGrade;

public:
    GradeBook(std::string);
    void setCourseName(std::string);
    std::string getCourseName();
    void displayMessage() ;
    void inputGrades() ;
    void displayGradeReport() ;
    int maximum(int, int, int) ;

};
