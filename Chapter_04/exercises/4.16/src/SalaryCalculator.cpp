#include "SalaryCalculator.hpp"

SalaryCalculator::SalaryCalculator()
{
    hourWorked = 0.0f;
    hourlyRate = 0.0f;
}

SalaryCalculator::~SalaryCalculator()
{
}

//Setters

void SalaryCalculator::setHourWorked(double hWorked)
{
    hourWorked = (hWorked > 0.0f) ? hWorked : -1;
}

void SalaryCalculator::setHourlyRate(double hRate)
{
    hourlyRate = hRate;
}

//Getters

double SalaryCalculator::getHourWorked() const
{
    return hourWorked;
}

double SalaryCalculator::getHourlyRate() const
{
    return hourlyRate;
}

double SalaryCalculator::getSalary() const
{
    if (getHourWorked() > BASEHOUR)
    {
        double overTime = getHourWorked() - BASEHOUR;
        double overTimePay = getHourlyRate() + (getHourlyRate() * 0.5);

        return (BASEHOUR * getHourlyRate()) + (overTime * overTimePay);
    }
    else
    {
        return (getHourWorked() * getHourlyRate());
    }
}

void SalaryCalculator::run()
{
    double dtemp;

    std::cout << std::setprecision(2)
              << std::fixed;

    std::cout << "\nEnter hours worked (-1 to end)             : ";
    std::cin >> dtemp;

    setHourWorked(dtemp);

    if (getHourWorked() != -1)
    {
        std::cout << "Enter hourly rate of the employee ($00.00) : ";
        std::cin >> dtemp;

        setHourlyRate(dtemp);

        std::cout << "Salary is                                  : $"
                  << getSalary()
                  << std::endl;
    }
}