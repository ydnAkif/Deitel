#include <iostream>

int integerPower(int, int);

int main()
{
    int base, exponent;
    std::cout << "A program to get Power"
              << std::endl
              << std::endl;

    std::cout << "Enter  base and expnent ";
    std::cin >> base >> exponent;

    std::cout << base
              << " ^ "
              << exponent
              << " = "
              << integerPower(base, exponent)
              << std::endl;
    return 0;
}

int integerPower(int b, int exp)
{
    int power = 1;
    for (unsigned int i = 1; i <= exp; ++i)
    {
        power *= b;
    }
    return power;
}