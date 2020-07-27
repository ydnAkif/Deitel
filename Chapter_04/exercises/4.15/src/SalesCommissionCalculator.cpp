#include "SalesCommissionCalculator.hpp"

SalesCommissionCalculator::SalesCommissionCalculator()
{
    weeklySales = 0.0f;
    weeklyEarnings = 0.0f;
}

SalesCommissionCalculator::~SalesCommissionCalculator()
{
}

//Setters
void SalesCommissionCalculator::setWeeklySales(double wSales)
{
    weeklySales = wSales;
}

void SalesCommissionCalculator::setWeeklyEarnings()
{
    weeklyEarnings = BASEPAY + (getWeeklySales() * COMMISSION);
}

//Getters

double SalesCommissionCalculator::getWeeklySales() const
{
    return weeklySales;
}

double SalesCommissionCalculator::getWeeklyEarnings() const
{
    return weeklyEarnings;
}

void SalesCommissionCalculator::run()
{
    double dtemp = 0.0f;
    std::cout << std::setprecision(2)
              << std::fixed;
    std::cout << "\nEnter sales in dollars (-1 to end) :  ";
    std::cin >> dtemp;

    setWeeklySales(dtemp);

    if (getWeeklySales() != -1)
    {
        setWeeklyEarnings();

        std::cout << "Salary is                          : $"
                  << getWeeklyEarnings()
                  << std::endl;
    }
}