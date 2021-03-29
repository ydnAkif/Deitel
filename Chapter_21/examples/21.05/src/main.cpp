#include <iostream>
#include <string>

void printStatistics(const std::string &);

int main(int argc, char const *argv[])
{
    std::string string1;

    std::cout << "Statistics before input:\n"
              << std::boolalpha;
    printStatistics(string1);

    std::cout << "\n\nEnter a string: ";
    std::cin >> string1;

    std::cout << "The string entered was: " << string1;

    std::cout << "\nStatistics after input:\n";
    printStatistics(string1);

    std::cin >> string1;
    std::cout << "\n\nThe remaining string is: " << string1 << std::endl;

    printStatistics(string1);

    string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
    std::cout << "\n\nstring1 is now: " << string1 << std::endl;

    printStatistics(string1);

    string1.resize(string1.size() + 10);
    std::cout << "\n\nStats after resizing by(length + 10):\n";
    printStatistics(string1);
    std::cout << std::endl;

    return 0;
}

void printStatistics(const std::string &stringRef)
{
    std::cout << "capacity: " << stringRef.capacity()
              << "\nmax size: " << stringRef.max_size()
              << "\nsize: " << stringRef.size()
              << "\nlength: " << stringRef.size()
              << "\nempty: " << stringRef.empty();
}