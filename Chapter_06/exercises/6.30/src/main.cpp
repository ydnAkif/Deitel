#include <iostream>

int reverseDigits(int);
int main()
{
    int n;

    std::cout << "A Program to reverse the digits of a given int"
              << std::endl
              << std::endl;

    std::cout << "Enter a number to reversed : ";
    std::cin >> n;

    std::cout << std::endl
              << reverseDigits(n)
              << std::endl;

    return 0;
}

int reverseDigits(int n)
{

    int reversed;
    int digits{1};

    for (unsigned int d = 1; d <= n; d *= 10)
    {
        digits *= 10;
    }

    while (n != 0)
    {
        digits /= 10;
        reversed += n % 10 * digits;
        n /= 10;
    }
    return reversed;
}