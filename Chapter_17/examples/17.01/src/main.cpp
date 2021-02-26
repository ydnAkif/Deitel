#include <iostream>
#include "DivideByZeroException.hpp"

double quotient(int, int);

int main(int argc, char const *argv[])
{
    int number1;
    int number2;

    std::cout << "Enter two integers (end-of-file to end): ";

    while (std::cin >> number1 >> number2)
    {
        try
        {
            double result = quotient(number1, number2);
            std::cout << "The quotient is: " << result << std::endl;
        }
        catch (DivideByZeroException &divideByZeroException)
        {
            std::cout << "Exception occurred: " << divideByZeroException.what() << std::endl;
        }

        std::cout << "Enter two integers (end-of-file to end): ";
    }

    std::cout << std::endl;

    return 0;
}

double quotient(int numerator, int denominator)
{
    if (denominator == 0)
        throw DivideByZeroException();

    return static_cast<double>(numerator) / denominator;
}