#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double rate{.05f};
    int principal{1000};

    std::cout << "Year"
              << std::setw(21)
              << "Amount on deposit"
              << std::endl;
    std::cout << std::fixed
              << std::setprecision(2);
    for (int year = 0; year <= 10; ++year)
    {
        int amount = principal * pow(1.0f + rate, year);
        int dollars = amount / 100;
        int cents = amount % 100;

        std::cout << std::setw(4)
                  << year
                  << std::setw(12)
                  << dollars
                  << '.';
        (cents < 10) ? (std::cout << "0" << cents) : (std::cout << cents);
        std::cout << std::endl;
    }

    return 0;
}