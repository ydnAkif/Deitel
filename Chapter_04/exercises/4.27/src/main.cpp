/******************************************************************************
 
 Exercises 4.27
 
 (Printing the Decimal Equivalent of a Binary Number) Input an integer 
 containing only 0s and 1s (i.e., a “binary” integer) and print its decimal 
 equivalent. Use the modulus and division operators to pick off the “binary” 
 number’s digits one at a time from right to left. Much as in the decimal number 
 system, where the rightmost digit has a positional value of 1, the next digit 
 left has a positional value of 10, then 100, then 1000, and so on, in the binary 
 number system the rightmost digit has a positional value of 1, the next digit 
 left has a positional value of 2, then 4, then 8, and so on. Thus the decimal 
 number 234 can be interpreted as 2 * 100 + 3 * 10 + 4 * 1. The decimal 
 equivalent of binary 1101 is 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8 
 or 1 + 0 + 4 + 8, or 13. 
 [Note: To learn more about binary numbers, refer to Appendix D.]
  
******************************************************************************/

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
