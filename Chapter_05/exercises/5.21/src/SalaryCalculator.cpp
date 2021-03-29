#include <iostream>
#include "SalaryCalculator.hpp"
#include <iomanip>

SalaryCalculator::SalaryCalculator()
{
}

//Setters
void SalaryCalculator::setManagerRate(double rate)
{
    if (rate > 0.0f)
    {
        managerRate = rate;
    }
    else
    {
        std::cout << "Manager rate must be > 0.0"
                  << std::endl;
    }
}
void SalaryCalculator::setHourlyRate(double rate)
{
    if (rate > 0.0f)
    {
        hourlyRate = rate;
    }
    else
    {
        std::cout << "Hourly rate must be > 0.0"
                  << std::endl;
    }
}
void SalaryCalculator::setWeeklySales(double sales)
{
    weeklySales = sales;
    if (sales == 0.0f)
    {
        std::cout << std::endl
                  << "Poor thing!. You sold nothing all week :( "
                  << std::endl
                  << std::endl;
    }
}
void SalaryCalculator::setHoursWorked(double hw)
{
    if (hw >= 0.0f)
    {
        hoursWorked = hw;
    }
    else
    {
        std::cout << "Hours worked must be >= 0.0"
                  << std::endl;
    }
}
void SalaryCalculator::setEmployeeCode(int emp)
{
    if (emp >= 1 && emp <= 4)
    {
        employeeCode = emp;
    }
    else
    {
        std::cout << "Invalid employe code!! (1-4)"
                  << std::endl;
    }
}
void SalaryCalculator::setPiecesProduced(int pieces)
{
    piecesProduced = pieces;
    if (pieces == 0.0f)
    {
        std::cout << std::endl
                  << "Poor little fella made nothing this week :("
                  << std::endl
                  << std::endl;
    }
}

//Getters

double SalaryCalculator::getManagerRate() const
{
    return managerRate;
}
double SalaryCalculator::getHourlyRate() const
{
    return hourlyRate;
}
double SalaryCalculator::getWeeklySales() const
{
    return weeklySales;
}
double SalaryCalculator::getHoursWorked() const
{
    return hoursWorked;
}
int SalaryCalculator::getEmployeeCode() const
{
    return employeeCode;
}
int SalaryCalculator::getPiecesProduced() const
{
    return piecesProduced;
}

void SalaryCalculator::inputSalaries()
{
    int iValue{0};

    std::cout << "Salary Calculator"
              << std::endl;

    while (iValue != -1)
    {
        std::cout << "Enter an employe code (1-4). -1 to exit ";
        std::cin >> iValue;

        if (iValue != -1)
        {
            setEmployeeCode(iValue);
        }
        if (iValue >= 1 && iValue <= 4)
        {
            calculateSalary();
            reset();
        }
    }
}
double SalaryCalculator::calculateSalary()
{
    double dValue{0.0f};
    switch (getEmployeeCode())
    {
    case 1:
        std::cout << std::endl
                  << "Enter manager weekly salary: ";
        std::cin >> dValue;
        setManagerRate(dValue);
        std::cout << "Manager Salary: $"
                  << std::fixed
                  << std::setprecision(2)
                  << getManagerRate()
                  << std::endl
                  << std::endl;
        break;
    case 2:
        std::cout << std::endl
                  << "Enter hourly rate: ";
        std::cin >> dValue;
        if (dValue > 0.0f)
        {
            setHourlyRate(dValue);
            std::cout << "Enter hours worked: ";
            std::cin >> dValue;
            setHoursWorked(dValue);
            dValue = getHourlyRate();
            dValue *= (getHoursWorked() <= 40.0f) ? getHoursWorked() : 40.0f;
            if (getHoursWorked() > 40.0f)
            {
                dValue += ((getHoursWorked() - 40.0f) * (getHourlyRate() * HOURLY_OVERTIME));
            }
            std::cout << "Hourly Worker Salary: $"
                      << std::fixed
                      << std::setprecision(2)
                      << dValue
                      << std::endl
                      << std::endl;
        }
        break;
    case 3:
        std::cout << std::endl
                  << "Enter gross weekly sales: ";
        std::cin >> dValue;

        setWeeklySales(dValue);
        dValue = COMMISSION_BASE + (getWeeklySales() * COMMISSION_RATE);
        std::cout << "Commission worker Salary: $"
                  << std::fixed
                  << std::setprecision(2)
                  << dValue
                  << std::endl
                  << std::endl;
        break;
    case 4:
        std::cout << std::endl
                  << "Enter pieces produced: ";
        std::cin >> dValue;
        setPiecesProduced(dValue);
        std::cout << "Piece Worker Salary: $"
                  << std::fixed
                  << std::setprecision(2)
                  << getPiecesProduced() * PIECE_RATE
                  << std::endl
                  << std::endl;
        break;
    default:
        std::cout << "Incorrect employee code entered" << std::endl;
        break;
    }
    return dValue;
}

void SalaryCalculator::reset()
{
    managerRate = 0.0f;
    hourlyRate = 0.0f;
    weeklySales = 0.0f;
    hoursWorked = 0.0f;

    employeeCode = 0;
    piecesProduced = 0;
}