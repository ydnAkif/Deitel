#include <iostream>
#include <iomanip>

void displayBits(unsigned int);

int main(int argc, char const *argv[])
{
    unsigned int number1 = 2179876355;
    unsigned int mask = 1;

    std::cout << "The result of combining the following\n";
    displayBits(number1);
    displayBits(mask);
    std::cout << "using the bitwise AND operator & is\n";
    displayBits(number1 & mask);

    number1 = 15;
    unsigned int setBits = 241;
    std::cout << "\nThe result of combining the following\n";
    displayBits(number1);
    displayBits(setBits);
    std::cout << "using the bitwise inclusive OR operator | is\n";
    displayBits(number1 | setBits);

    number1 = 139;
    unsigned int number2 = 199;
    std::cout << "\nThe result of combining the following\n";
    displayBits(number1);
    displayBits(number2);
    std::cout << "using the bitwise exclusive OR operator ^ is\n";
    displayBits(number1 ^ number2);

    number1 = 21845;
    std::cout << "\nThe one's complement of\n";
    displayBits(number1);

    std::cout << "is" << std::endl;
    displayBits(~number1);

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