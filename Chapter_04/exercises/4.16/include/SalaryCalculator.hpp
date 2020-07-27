#include <iostream>
#include <iomanip>

class SalaryCalculator
{
private:
    const double BASEHOUR = 40.0f;
    double hourWorked;
    double hourlyRate;

public:
    SalaryCalculator();
    ~SalaryCalculator();

    //Setters

    void setHourWorked(double);
    void setHourlyRate(double);

    //Getters

    double getHourWorked() const;
    double getHourlyRate() const;
    double getSalary() const;

    void run();
};
