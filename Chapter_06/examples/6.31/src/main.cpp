#include <iostream>
#include <iomanip>

unsigned int factorial(unsigned int);

int main()
{
    for (unsigned int counter = 0; counter <= 10; ++counter)
    {
        std::cout << std::setw(2)
                  << counter
                  << "! = "
                  << factorial(counter)
                  << std::endl;
    }

    return 0;
}

unsigned int factorial(unsigned int number)
{
    unsigned int result = 1;

    for (unsigned int i = number; i >= 1; --i)
    {
        result *= i;
    }

    return result;
}