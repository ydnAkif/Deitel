#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s, '\n');

    std::string::reverse_iterator r = s.rbegin();
    while (r != s.rend())
    {
        *r = (isupper(*r) ? tolower(*r) : toupper(*r));
        std::cout << *(r++);
    }

    std::cout << std::endl;

    return 0;
}
