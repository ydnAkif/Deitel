#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("cat");
    std::string string2;
    std::string string3;

    string2 = string1;
    string3.assign(string1);

    std::cout << "string1: " << string1 << "\nstring2: " << string2
              << "\nstring3: " << string3 << "\n\n";

    string2[0] = string3[2] = 'r';

    std::cout << "After modification of string2 and string3:\n"
              << "string1: " << string1
              << "\nstring2: " << string2 << "\nstring3: ";

    for (size_t i = 0; i < string3.size(); ++i)
        std::cout << string3.at(i);

    std::string string4(string1 + "apult");
    std::string string5;

    string3 += "pet";
    string1.append("acomb");
    string5.append(string1, 4, string1.size() - 4);

    std::cout << "\n\nAfter concatenation:\nstring1: " << string1
              << "\nstring2: " << string2 << "\nstring3: " << string3
              << "\nstring4: " << string4 << "\nstring5: " << string5 << std::endl;

    return 0;
}
