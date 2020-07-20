#include <string>

class HeartRates
{
private:
    std::string firstName;
    std::string lastName;
    int day = 1;
    int month = 1;
    int year = 1900;
    int ageOfYears = 0;

public:
    HeartRates(std::string, std::string, int, int, int);

    //Setters

    void setFirstName(std::string);
    void setLastName(std::string);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setBirthDay(int, int, int);
    void setAge();

    //Getters

    std::string getFirstName() const;
    std::string getLastName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getAge() const;
    int getMaxiumumHeartRate() const;
    void getTargetHeartRate() const;

    void displayInformation() const;
};
