#include <iostream>
#include <iomanip>

unsigned long factorial(unsigned long);

int main()
{
    for (unsigned int counter = 0; counter <= 10; ++counter)
    {
        std::cout << std::setw(2)
                  << counter
                  << "!= "
                  << factorial(counter)
                  << std::endl;
    }

    return 0;
}

unsigned long factorial(unsigned long number)
{
    if (number <= 1)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}