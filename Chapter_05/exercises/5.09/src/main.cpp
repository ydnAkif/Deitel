#include <iostream>

// 1*3*5*7*9*11*13*15

int main()
{
    int productOdd = 1;

    for (int i = 1; i <= 15; i += 2)
    {
        productOdd *= i;
    }

    std::cout << "the product of the odd integers from 1 to 15 = " << productOdd << std::endl;

    return 0;
}