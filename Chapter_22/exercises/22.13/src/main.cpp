#include <iostream>

bool mystery(unsigned);

int main(int argc, char const *argv[])
{
    unsigned x;

    std::cout << "Enter an integer: ";
    std::cin >> x;

    std::cout << std::boolalpha
              << "The result is " << mystery(x) << std::endl;

    return 0;
}

bool mystery(unsigned bits)
{
    const int SHIFT = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1 << SHIFT;
    unsigned total = 0;

    for (int i = 0; i < SHIFT + 1; ++i, bits <<= 1)
        if ((bits & MASK) == MASK)
            ++total;
    return !(total % 2);
}