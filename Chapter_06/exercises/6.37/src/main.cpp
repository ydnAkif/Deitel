#include <iostream>

int fibonacci(int);
int main()
{
    int n;

    std::cout << "A Program to non recursively calculate fibonacci to n"
              << std::endl;
    std::cout << "Enter the n: ";
    std::cin >> n;

    std::cout << "Fibonacci to the "
              << n
              << "th power: "
              << fibonacci(n)
              << std::endl;
    return 0;
}

int fibonacci(int n)
{
    int firsTerm{0};
    int secondTerm{1};
    int fib{0};

    for (unsigned int i = 0; i < n; ++i)
    {
        if (i <= 1)
        {
            fib = i;
        }
        else
        {
            fib = firsTerm + secondTerm;
            firsTerm = secondTerm;
            secondTerm = fib;
        }
    }

    return fib;
}