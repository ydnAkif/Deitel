#include <iostream>
#include <iomanip>

unsigned long factorial(unsigned long);
int main()
{
    for (unsigned int counter = 0; counter <= 10; ++counter)
    {
        std::cout << counter << "! = "
                  << factorial(counter)
                  << std::endl
                  << std::endl;
    }

    return 0;
}

unsigned long factorial(unsigned long number)
{
    if (number <= 1)
    {
        std::cout << 1
                  << " = ";
        return 1;
    }
    else
    {
        std::cout << number
                  << " * ";
        return number * factorial(number - 1);
    }
}