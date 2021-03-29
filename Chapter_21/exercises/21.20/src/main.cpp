#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{

    std::string s;

    std::cout << "Enter a string: ";
    std::getline(std::cin, s, '\n');

    std::string::reverse_iterator rb = s.rbegin();

    while (rb != s.rend())
    {
        std::cout << *rb;
        ++rb;
    }

    return 0;
}
