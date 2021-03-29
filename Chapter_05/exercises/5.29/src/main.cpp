#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double amount{0};
    double principal{24.0f};

    std::cout << std::fixed << std::setprecision(2);

    for (double rate{0.05}; rate <= 0.10; rate += 0.01)
    {
        std::cout << std::endl
                  << "Interest rate: "
                  << rate * 100
                  << "%"
                  << std::endl
                  << "Year"
                  << std::setw(30)
                  << "Amount on deposit"
                  << std::endl;

        for (int year{1626}; year <= 2020; ++year)
        {
            amount = principal * pow(1 + rate, year - 1626);

            if (year == 1626 || year == 2008 || year == 2010 || year == 2020 || year % 50 == 0)
            {
                std::cout << std::setw(4)
                          << year
                          << std::setw(30)
                          << amount
                          << std::endl;
            }
        }
    }

    return 0;
}