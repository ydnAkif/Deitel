#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Binary"
              << std::setw(9)
              << "Octal"
              << std::setw(15)
              << "Hexadecimal"
              << std::endl;
    for (int i = 1; i <= 256; ++i)
    {
        std::cout << std::setw(3)
                  << std::dec
                  << i
                  << std::setw(9)
                  << std::oct
                  << i
                  << std::setw(15)
                  << std::hex
                  << i
                  << std::endl;
    }

    return 0;
}