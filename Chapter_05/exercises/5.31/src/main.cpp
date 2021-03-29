#include <iostream>

const double FAIR_TAX{0.23f};

double calculateTax(double);
int main()
{
    double dAmount{0.0f};
    double dAmountTotal{0.0f};

    std::cout << "Program to calculate tax rate of %23"
              << std::endl;
    while (dAmount != -1)
    {
        std::cout << std::endl
                  << "Enter expences (-1 to quit): ";
        std::cin >> dAmount;

        if (dAmount > 0)
        {
            dAmountTotal += dAmount;
        }
    }

    std::cout << "Total amount: "
              << dAmountTotal
              << std::endl;
    std::cout << "Tax: "
              << calculateTax(dAmountTotal)
              << std::endl;
    return 0;
}

double calculateTax(double baseAmount)
{
    return baseAmount * FAIR_TAX;
}