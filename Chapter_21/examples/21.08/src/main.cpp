#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("beginning end");
    std::string string2("middle ");
    std::string string3("12345678");
    std::string string4("xx");

    std::cout << "Initial strings:\nstring1: " << string1
              << "\nstring2: " << string2 << "\nstring3: " << string3
              << "\nstring4: " << string4 << "\n\n";

    string1.insert(10, string2);
    string3.insert(3, string4, 0, std::string::npos);

    std::cout << "Strings after insert:\nstring1: " << string1
              << "\nstring2: " << string2 << "\nstring3: " << string3
              << "\nstring4: " << string4 << "\n";

    return 0;
}
