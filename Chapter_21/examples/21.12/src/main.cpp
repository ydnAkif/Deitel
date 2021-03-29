#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string input("Input test 123 4.7 A");
    std::istringstream inputStrings(input);
    std::string string1;
    std::string string2;
    int integer;
    double double1;
    char character;

    inputStrings >> string1 >> string2 >> integer >> double1 >> character;

    std::cout << "The following items were extracted\n"
              << "from the istringstream object:"
              << "\nstring1: " << string1
              << "\nstring2: " << string2 << "\n    int: " << integer
              << "\ndouble1: " << double1 << "\n   char: " << character;

    long value;
    inputStrings >> value;

    if (inputStrings.good())
        std::cout << "\n\nlong value is: " << value << std::endl;
    else
        std::cout << "\n\ninputString is empty" << std::endl;

    return 0;
}
