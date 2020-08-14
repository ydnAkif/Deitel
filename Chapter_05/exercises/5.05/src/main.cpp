#include <iostream>

int main()
{
    int num, total{0}, count;

    std::cout << "Enter the number of values to be summed followed by values: ";
    std::cin >> count;

    for (int i = 1; i <= count; ++i)
    {
        std::cin >> num;
        total += num;
    }

    std::cout << "Total = " << total << std::endl;
    return 0;
}