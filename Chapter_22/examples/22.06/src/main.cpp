#include <iostream>
#include <iomanip>

void displayBits(unsigned int);

int main(int argc, char const *argv[])
{
    unsigned int inputValue = 0;

    std::cout << "Enter an unsigned integer: ";
    std::cin >> inputValue;

    displayBits(inputValue);

    return 0;
}

void displayBits(unsigned int value)
{
    const int SHIFT = 8 * sizeof(unsigned int) - 1;
    const unsigned int MASK = 1 << SHIFT;

    std::cout << std::setw(10) << value << " = ";

    for (unsigned int i = 1; i <= SHIFT + 1; ++i)
    {
        std::cout << (value & MASK ? '1' : '0');
        value <<= 1;

        if (i % 8 == 0)
            std::cout << ' ';
    }

    std::cout << std::endl;
}