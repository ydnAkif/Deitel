#include <iostream>
#include <iomanip>

class SalesCommissionCalculator
{
private:
    const double COMMISSION = 0.09f;
    const double BASEPAY = 200.00f;
    double weeklySales;
    double weeklyEarnings;

public:
    SalesCommissionCalculator();
    ~SalesCommissionCalculator();

    //Setters
    void setWeeklySales(double);
    void setWeeklyEarnings();

    //Getters

    double getWeeklySales() const;
    double getWeeklyEarnings() const;

    void run();
};