#include <iostream>
#include <iomanip>
#include <array>

int main()
{

    std::array<int, 5> n;

    for (size_t i = 0; i <= n.size() - 1; i++)
    {
        n[i] = 0;
    }
    std::cout << "Element"
              << std::setw(13)
              << "Value"
              << std::endl;
    for (size_t j = 0; j <= n.size() - 1; j++)
    {
        std::cout << std::setw(7)
                  << j
                  << std::setw(13)
                  << n[j]
                  << std::endl;
    }

    return 0;
}