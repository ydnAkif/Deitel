#include <iostream>
#include <cmath>
#include <iomanip>

bool isPrime(int);

int main()
{
    int counter{0};
    std::cout << "A program to print all prime numbers between 2 and 10k"
              << std::endl
              << std::endl;
    for (unsigned int i = 2; i <= 10000; ++i)
    {
        if (isPrime(i))
        {
            ++counter;

            std::cout << std::setw(10)
                      << i
                      << " ";

            if (counter % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl
              << std::endl
              << "There is "
              << counter
              << " prime numbers."
              << std::endl;

    return 0;
}

bool isPrime(int n)
{
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (unsigned int i = 2; i <= static_cast<int>(sqrt(n)); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}