#include <iostream>

bool multiple(int);

int main(int argc, char const *argv[])
{
    int y = 0;

    std::cout << "Enter an integer between 1 and 32000: ";
    std::cin >> y;

    if (multiple(y))
        std::cout << y << " is a multiple of X" << std::endl;
    else
        std::cout << y << " is not a multiple of X" << std::endl;

    return 0;
}

bool multiple(int num)
{
    bool mult = true;

    for (int i = 0, mask = 1; i < 10; ++i, mask <<= 1)
        if ((num & mask) != 0)
        {
            mult = false;
            break;
        }

    return mult;
}