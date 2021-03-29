#include <string>

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
    explicit GradeBook(std::string);

    void setCourseName(std::string);

    std::string getCourseName() const;
    double getAvarage() const;
    void displayMessage() const;
    void inputGrades();
    void displayGradeReports() const;
};
