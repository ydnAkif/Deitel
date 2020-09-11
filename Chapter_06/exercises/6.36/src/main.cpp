#include <iostream>

int power(int, int);
int main()
{
    int base, exponent;
    std::cout << "A program to recursively calculate exponents"
              << std::endl;

    std::cout << std::endl
              << "Enter the base and exponent ";
    std::cin >> base >> exponent;

    std::cout << base
              << " to power of "
              << exponent
              << " : "
              << power(base, exponent)
              << std::endl;
    return 0;
}

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    return (base * power(base, exponent - 1));
}