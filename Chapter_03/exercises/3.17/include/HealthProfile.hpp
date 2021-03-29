#include <string>

class HealthProfile
{
private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int day, month, year;
    double height, weight;
    int ageOfYear = 0;

public:
    HealthProfile(std::string, std::string,
                  std::string, int, int,
                  int, double, double);

    //Setters

    void setFirstName(std::string);
    void setLastName(std::string);
    void setGender(std::string);

    void setBirthday(int, int, int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setAge();

    void setHeight(double);
    void setWeight(double);

    //Getters

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void getBirthday() const;
    int getAge();

    double getHeight() const;
    double getWeight() const;
    double getBMI() const;

    int getMaxHeartRate();
    void getTargetHeartRate();

    void showHealthProfile();
    void displayBMIInfo() const;
};
