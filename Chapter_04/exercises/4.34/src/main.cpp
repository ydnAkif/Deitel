#include <iostream>

int getFactorial(int);

int main(int argc, char const *argv[])
{
    int number;
    std::cout << "A Program to determine the factorial of nonzero integers"
              << std::endl;
    std::cout << "Enter a nonzero integer: ";
    std::cin >> number;
    std::cout << number
              << "! = "
              << getFactorial(number)
              << std::endl;
    return 0;
}

int getFactorial(int n)
{
    int factorial{1}, counter{1};

    while (n > 0)
    {
        factorial *= n;
        n--;
    }

    return factorial;
}
