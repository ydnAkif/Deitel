#include <iostream>
#include <iomanip>
unsigned long fibonacci(unsigned long);

int main()
{
    for (unsigned int counter = 0; counter <= 10; ++counter)
    {
        std::cout << "fibonacci( "
                  << std::setw(2)
                  << counter
                  << " ) = "
                  << fibonacci(counter)
                  << std::endl;
    }

    std::cout << std::endl
              << "fibonacci( 20 ) = "
              << fibonacci(20)
              << std::endl;
    std::cout << std::endl
              << "fibonacci( 30 ) = "
              << fibonacci(30)
              << std::endl;
    std::cout << std::endl
              << "fibonacci( 35 ) = "
              << fibonacci(35)
              << std::endl;

    return 0;
}

unsigned long fibonacci(unsigned long number)
{
    if (0 == number || 1 == number)
    {
        return number;
    }
    else
    {
        return (fibonacci(number - 1) + fibonacci(number - 2));
    }
}