#include <iostream>
#include <string>

void printBackwards(const std::string::reverse_iterator, std::string::reverse_iterator);

int main(int argc, char const *argv[])
{
    std::string s;

    std::cout << "Enter a string: ";
    std::getline(std::cin, s, '\n');

    std::string::reverse_iterator rb = s.rbegin();
    std::string::reverse_iterator re = s.rend();

    printBackwards(rb, re - 1);

    std::cout << std::endl;

    return 0;
}

void printBackwards(const std::string::reverse_iterator rb, std::string::reverse_iterator re)
{
    if (rb == re - 1)
        return;
    printBackwards(rb, re - 1);
    std::cout << *re;
}
