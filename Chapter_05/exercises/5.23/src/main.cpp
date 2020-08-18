#include <iostream>
#include <cmath>
int main()
{

    for (int i{1}, j{1}, k{4}; i <= 9; i++)
    {
        for (int s{0}; s < k; s++)
        {
            std::cout << " ";
        }
        for (int d{0}; d < j; d++)
        {
            std::cout << "*";
        }
        (i >= 5) ? j -= 2 : j += 2;
        (i >= 5) ? k++ : k--;

        std::cout << std::endl;
    }

    return 0;
}