#include <iostream>

void squareOfChars(int, char);
int main()
{
    int side{0};
    char fillChar;
    std::cout << "Program to print a square of size n of any character"
              << std::endl
              << std::endl;
    std::cout << "Enter side of square : ";
    std::cin >> side;
    std::cout << "Enter char to fill : ";
    std::cin >> fillChar;

    squareOfChars(side, fillChar);

    return 0;
}

void squareOfChars(int n, char ch)
{
    for (unsigned int row = 1; row <= n; ++row)
    {
        for (unsigned int column = 1; column <= n; ++column)
        {
            std::cout << ch;
        }

        std::cout << std::endl;
    }
}