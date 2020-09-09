#include <iostream>

void displaySquare(int);

int main()
{
    unsigned int side{0};
    std::cout << "Program to display a square of asterisks of size n"
              << std::endl
              << std::endl;
    std::cout << "Enter the side of square : ";
    std::cin >> side;

    displaySquare(side);

    return 0;
}

void displaySquare(int n)
{
    for (unsigned int row = 1; row <= n; ++row)
    {
        for (unsigned int column = 1; column <= n; ++column)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}