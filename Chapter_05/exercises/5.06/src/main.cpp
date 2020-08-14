#include <iostream>

int average(int, int);

static const int EXIT = 9999;
int main()
{
    int counter{0};
    int sum{0};

    std::cout << "Enter a list of space separated integers for average calculation. "
              << EXIT << " ends input" << std::endl;
    std::cin >> sum;

    for (int i = 0; i != EXIT; ++counter)
    {
        sum += i;
        std::cin >> i;
    }

    std::cout << "Average of sum: " << average(sum, counter) << std::endl;

    return 0;
}

int average(int a, int b)
{
    return (a / b);
}