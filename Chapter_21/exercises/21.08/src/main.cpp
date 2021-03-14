#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string s("abcdefghijklmnopqrstuvwxyz");

    std::string::reverse_iterator re = s.rend();

    std::string::reverse_iterator rb = s.rbegin();

    std::cout << "Using rend() string is: ";

    while (re >= s.rbegin())
    {
        std::cout << *re;
        --re;
    }

    std::cout << "\nUsing rbegin() string is: ";

    while (rb != s.rend())
    {
        std::cout << *rb;
        ++rb;
    }

    std::cout << std::endl;

    return 0;
}
