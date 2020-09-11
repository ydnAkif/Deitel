#include <iostream>

int gcd(int, int);

int main()
{
    int num1, num2;
    std::cout << "A Program to find the gcd of two integers"
              << std::endl
              << std::endl;
    std::cout << "Enter two integers : ";
    std::cin >> num1 >> num2;

    std::cout << "Greatest Common Divisor : "
              << gcd(num1, num2)
              << std::endl;

    return 0;
}

int gcd(int a, int b)
{
    int R;

    while (a % b > 0)
    {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}