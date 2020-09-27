#include <iostream>
#include <iomanip>
#include <array>

int main(int argc, char const *argv[])
{

    const size_t arraySize = 5;

    std::array<int, arraySize> s;

    for (size_t i = 0; i < s.size(); ++i)
    {
        s[i] = 2 + 2 * i;
    }

    std::cout << "Element"
              << std::setw(13)
              << "Value"
              << std::endl;

    for (size_t j = 0; j < s.size(); ++j)
    {
        std::cout << std::setw(7)
                  << j
                  << std::setw(13)
                  << s[j]
                  << std::endl;
    }

    return 0;
}
