#include <iostream>
#include <iomanip>

void displayBits(unsigned);

int main(int argc, char const *argv[])
{
    unsigned val;

    std::cout << "Enter an integer: ";
    std::cin >> val;

    std::cout << "Before right shifting 4 bits is:\n";
    displayBits(val);
    std::cout << "After right shifting 4 bits is:\n";
    displayBits(val >> 4);

    return 0;
}

void displayBits(unsigned value)
{
    const int SHIFT = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1 << SHIFT;

    std::cout << std::setw(7) << value << " = ";

    for (unsigned i = 1; i <= SHIFT + 1; ++i)
    {
        std::cout << (value & MASK ? '1' : '0');
        value <<= 1;

        if (i % 8 == 0)
            std::cout << ' ';
    }

    std::cout << std::endl;
}
