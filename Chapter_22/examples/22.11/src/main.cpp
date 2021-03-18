#include <iostream>
#include <iomanip>

void displayBits(unsigned int);

int main(int argc, char const *argv[])
{
    unsigned int number1 = 960;

    std::cout << "The result of left shifting\n";
    displayBits(number1);

    std::cout << "8 bit positions using left-shift operator is\n";
    displayBits(number1 << 8);

    std::cout << "\nThe result of right shifting\n";
    displayBits(number1);
    std::cout << "8 bit positions using right-shift operator is\n";
    displayBits(number1 >> 8);

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
