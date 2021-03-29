#include <string>

class GradeBook
{
private:
    std::string courseName;

public:
    explicit GradeBook(std::string);
    void setCourseName(std::string);
    std::string getCourseName() const;
    void displayMessage() const;
    void determineClassAvarage() const;
};
