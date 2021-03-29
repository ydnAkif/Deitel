#include "Point.hpp"

std::ostream &operator<<(std::ostream &output, Point &p)
{
    if (!std::cin.fail())
        std::cout << "(" << p.xCoordinate << ",  " << p.yCoordinate << ")" << '\n';
    else
        std::cout << "Invalid data\n";

    return output;
}

std::istream &operator>>(std::istream &input, Point &p)
{
    if (std::cin.peek() != '(')
        std::cin.clear(std::ios::failbit);
    else
        input.ignore();

    std::cin >> p.xCoordinate;

    if (std::cin.peek() != ',')
        std::cin.clear(std::ios::failbit);
    else
    {
        input.ignore();

        if (std::cin.peek() == ' ')
            input.ignore();
        else
            std::cin.clear(std::ios::failbit);
    }

    std::cin >> p.yCoordinate;

    if (std::cin.peek() == ')')
        input.ignore();
    else
        std::cin.clear(std::ios::failbit);

    return input;
}