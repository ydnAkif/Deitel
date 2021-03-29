#include <iostream>

int gcd(int, int);

int main()
{
    int x, y;

    std::cout << "A Program to recursively find the gcd of two numbers"
              << std::endl;

    std::cout << "Enter x and y: ";
    std::cin >> x >> y;

    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    std::cout << "Great Common Divisor of "
              << x
              << " and "
              << y
              << " is "
              << gcd(x, y)
              << std::endl;

    return 0;
}

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}