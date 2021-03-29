#include <iostream>
#include <iomanip>

unsigned packCharacters(char, char);

void displayBits(unsigned);

int main(int argc, char const *argv[])
{
    char a;
    char b;
    unsigned result;

    std::cout << "Enter two characters: ";
    std::cin >> a >> b;

    std::cout << "\n\'" << a << '\'' << " in bits as an unsigned integer is:\n";
    displayBits(a);
    std::cout << '\'' << b << '\'' << " in bits as an unsigned integer is:\n";
    displayBits(b);

    result = packCharacters(a, b);
    std::cout << "\n\'"
              << a << '\'' << " and " << '\'' << b << '\''
              << " packed in an unsigned integer:\n";
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

unsigned packCharacters(char x, char y)
{
    unsigned pack = x;
    pack <<= 8;
    pack |= y;
    return pack;
}