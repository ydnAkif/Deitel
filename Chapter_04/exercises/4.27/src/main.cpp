#include <iostream>

int binaryToDecimal(int bin);

int main(int argc, char const *argv[])
{
    int binary{0};

    std::cout << "Printing the decimal equivalent of a binary number"
              << std::endl
              << std::endl;

    std::cout << "Enter a binary number for decimal conversion: ";
    std::cin >> binary;

    std::cout << binary
              << " as decimal = "
              << binaryToDecimal(binary)
              << std::endl;

    return 0;
}

int binaryToDecimal(int bin)
{
    int decimal{0}, value{1};

    while (bin != 0)
    {
        decimal += (bin % 10) * value;
        bin /= 10;
        value += value;
    }
    return decimal;
}

