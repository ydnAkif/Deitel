#include <iostream>

int main()
{
    unsigned int total{0};

    for (unsigned int number = 2; number <= 20; number += 2)
    {
        total += number;
    }

    std::cout << "Sum of the even integers from 2 to 20 = "
              << total
              << std::endl;

    return 0;
}