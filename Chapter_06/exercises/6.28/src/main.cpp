#include <iostream>
#include <iomanip>

bool isPerfect(unsigned long long);

int main()
{
    std::cout << "A Program to test whether a number is perfect or not"
              << std::endl
              << std::endl;
    std::cout << "Perfect number between 1 and 10000: "
              << std::endl;

    for (unsigned long long i = 1; i <= 10'000; ++i)
    {
        if (isPerfect(i))
        {
            std::cout << std::setw(12)
                      << i
                      << " : "
                      << "\t";

            for (unsigned long long d = 1; d < i; ++d)
            {
                if (i % d == 0)
                {
                    std::cout << d << " ";
                }
            }

            std::cout << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}

bool isPerfect(unsigned long long n)
{
    unsigned long long sum{0};

    for (unsigned long long i = 1; i <= (n / 2); ++i)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum == n;
}