#include <iostream>
#include <iomanip>

void displayBits(unsigned);

unsigned power2(unsigned, unsigned);

int main(int argc, char const *argv[])
{
    unsigned number;
    unsigned pow;
    unsigned result;

    std::cout << "Enter two integers: ";
    std::cin >> number >> pow;

    std::cout << "number:\n";
    displayBits(number);
    std::cout << "power:\n";
    displayBits(pow);
    result = power2(number, pow);
    std::cout << '\n'
              << number << " *  2^" << pow << " = " << result << '\n';
    displayBits(result);

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

unsigned power2(unsigned n, unsigned p)
{
    return n << p;
}