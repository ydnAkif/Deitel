#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("Testing the comparison functions.");
    std::string string2("Hello");
    std::string string3("stinger");
    std::string string4(string2);

    std::cout << "string1: " << string1 << "\nstring2: " << string2
              << "\nstring3: " << string3 << "\nstring4: " << string4 << "\n\n";

    if (string1 == string2)
        std::cout << "string1 == string4\n";
    else if (string1 > string4)
        std::cout << "string1 > string4\n";
    else
        std::cout << "string1 < string4\n";

    int result = string1.compare(string2);

    if (result == 0)
        std::cout << "string1.compare(string2) == 0\n";
    else if (result > 0)
        std::cout << "string1.compare(string2) > 0\n";
    else
        std::cout << "string1.compare(string2) < 0\n";

    result = string1.compare(2, 5, string3, 0, 5);

    if (result == 0)
        std::cout << "string1.compare(2, 5, string3, 0, 5) == 0\n";
    else if (result > 0)
        std::cout << "string1.compare(2, 5, string3, 0, 5) > 0\n";
    else
        std::cout << "string1.compare(2, 5, string3, 0, 5) < 0\n";

    result = string4.compare(0, string2.size(), string2);

    if (result == 0)
        std::cout << "string4.compare(0, string2.size(), string2) == 0\n";
    else if (result > 0)
        std::cout << "string4.compare(0, string2.size(), string2) > 0\n";
    else
        std::cout << "string4.compare(0, string2.size(), string2) < 0\n";

    result = string2.compare(0, 3, string4);

    if (result == 0)
        std::cout << "string2.compare(0, 3, string4) == 0\n";
    else if (result > 0)
        std::cout << "string2.compare(0, 3, string4) > 0\n";
    else
        std::cout << "string2.compare(0, 3, string4) < 0\n";
    
    

    return 0;
}
