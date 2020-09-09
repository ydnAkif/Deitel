#include <iostream>

void seperateInt(long);

int main()
{
    long n;

    std::cout << "A program to print a separated a sequence of integers"
              << std::endl
              << std::endl;
    std::cout << "Enter the multi digit number : ";
    std::cin >> n;

    seperateInt(n);

    return 0;
}

void seperateInt(long n)
{
    long numDigits{1};

    for (long i = n; i > 10; i /= 10)
    {
        numDigits *= 10;
    }

    while (numDigits > 0)
    {
        std::cout << (n / numDigits) % 10 << " " ;

        numDigits /= 10;
    }

    std::cout << std::endl;
}
