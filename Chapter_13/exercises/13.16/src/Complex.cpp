#include <iomanip>
#include <iostream>
#include "Complex.hpp"

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

std::ostream &operator<<(std::ostream &output, Complex &c)
{
    if (!std::cin.fail())
        output << c.real
               << std::setiosflags(std::ios::showpos)
               << c.imaginary << " i\n"
               << std::resetiosflags(std::ios::showpos);
    else
        output << "Invalid Data Entered" << '\n';

    return output;
}

std::istream &operator>>(std::istream &input, Complex &c)
{
    int number, multiplier;
    char temp;

    input >> number;

    if (std::cin.peek() == ' ')
    {
        c.real = number;
        std::cin >> temp;

        multiplier = (temp == '+') ? 1 : -1;

        if (std::cin.peek() != ' ')
            std::cin.clear(std::ios::failbit);
        else
        {
            if (std::cin.peek() == ' ')
            {
                input >> c.imaginary;
                c.imaginary *= multiplier;

                std::cin >> temp;

                if (std::cin.peek() != '\n')
                    std::cin.clear(std::ios::failbit);
            }
            else
                std::cin.clear(std::ios::failbit);
        }
    }
    else if (std::cin.peek() == 'i')
    {
        std::cin >> temp;

        if (std::cin.peek() == '\n')
        {
            c.real = 0;
            c.imaginary = number;
        }
        else
            std::cin.clear(std::ios::failbit);
    }
    else if (std::cin.peek() == '\n')
    {
        c.real = number;
        c.imaginary = 0;
    }
    else
        std::cin.clear(std::ios::failbit);

    return input;
}
