#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("Testing iterators");
    std::string::const_iterator iterator1 = string1.begin();

    std::cout << "string1 = " << string1
              << "\n(Using iterator iterator1) string1 is: ";

    while (iterator1 != string1.end())
    {
        std::cout << *iterator1;
        ++iterator1;
    }

    std::cout << std::endl;

    return 0;
}
