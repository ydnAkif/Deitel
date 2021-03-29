#include <iostream>
#include <iomanip>
int factorial(int);
int factorialRecursive(int);

int main(int argc, const char *argv[])
{
    std::cout << "Factorials of 1 to 5\n"
              << std::endl;

    std::cout << "N" << std::setw(14) << "Factorial(N)" << std::endl;

    for (int i = 1; i <= 5; i++)
    {
        std::cout << i << std::setw(14) << factorial(i) << std::endl;
    }

    return 0;
}

// n! = n * (n-1) * (n-2) * (n-3) * ... * 1
int factorial(int n)
{
    int f = 1;

    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }

    return f;
}
/*
 * n! = n * (n-1) * (n-2) * (n-3) * ... * 1
 */
int factorialRecursive(int n)
{
    if (n >= 1)
    {
        return n * factorialRecursive(n - 1);
    }
    else
    {
        return 1;
    }
}
