#include <iostream>
#include <iomanip>

void unpackCharacters(char *const, char *const, unsigned);

void displayBits(unsigned);

int main(int argc, char const *argv[])
{
    char a;
    char b;
    unsigned packed = 16706;

    std::cout << "The packed character representation is:\n";
    displayBits(packed);

    unpackCharacters(&a, &b, packed);

    std::cout << "\nThe unpacked characters are \'"
              << a << '\'' << " and " << '\'' << b << "\'\n";

    displayBits(a);
    displayBits(b);

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

void unpackCharacters(char *const aPtr, char *const bPtr, unsigned pack)
{
    unsigned mask1 = 65280;
    unsigned mask2 = 255;

    *aPtr = static_cast<char>((pack & mask1) >> 8);
    *bPtr = static_cast<char>(pack & mask2);
}