#include <iostream>

bool isMultiple(int, int);

int main()
{
    int x, y, choice{0};
    std::cout << "A program to determine if first"
              << " integer is a multiple of a second "
              << std::endl;

    while (choice >= 0)
    {
        std::cout << "Enter two integer (-1 to quit ) : ";
        std::cin >> x;

        if (x == -1)
        {
            break;
        }

        std::cin >> y;

        std::cout << x
                  << " and "
                  << y
                  << (isMultiple(x, y) ? ": true" : ": false")
                  << std::endl;
    }

    return 0;
}

bool isMultiple(int x, int y)
{
    return (y % x == 0);
}