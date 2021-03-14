#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::ostringstream outputString;

    std::string string1("Output of several data types ");
    std::string string2("to an ostringstream onject:");
    std::string string3("\n        double: ");
    std::string string4("\n           int: ");
    std::string string5("\naddress of int: ");

    double double1 = 123.4567;
    int integer = 22;

    outputString << string1 << string2 << string3 << double1
                 << string4 << integer << string5 << &integer;
    std::cout << "outputString contains:\n"
              << outputString.str();

    outputString << "\nmore characters added";
    std::cout << "\n\nafter additional stream insertions,\n"
              << "outputString contains:\n"
              << outputString.str() << std::endl;

    return 0;
}
