#include <string>

class GradeBook
{
private:
   std::string courseName;
   std::string instructorName;

public:
   GradeBook(std::string, std::string);

   // SETTERS
   void setCourseName(std::string);
   void setInstructorName(std::string);

   // GETTERS
   std::string getCourseName() const;
   std::string getInstructorName()const;

   void displayMessage()const;
};