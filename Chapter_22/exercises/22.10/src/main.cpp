#include <iostream>
#include <iomanip>

void reverseBits(unsigned *const);
void displayBits(unsigned);

int main(int argc, char const *argv[])
{
    unsigned a;

    std::cout << "Enter an unsigned integer: ";
    std::cin >> a;

    std::cout << "\nBefore bits are reversed:\n";
    displayBits(a);

    std::cout << "\nAfter bits are reversed:\n";
    reverseBits(&a);
    displayBits(a);

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

void reverseBits(unsigned *const vPtr)
{

    const int SHIFT = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1;
    unsigned value = *vPtr;

    for (int i = 0; i <=15; ++i)
    {
        *vPtr <<= 1;
        *vPtr |= (value & MASK);
        value >>= 1;
    }
    
}