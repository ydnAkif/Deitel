#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "A zoo has many animals including zebras";
    char c = 'z';

    std::cout << "string1 = " << string1 << "\n"
              << std::endl;
    std::cout << "The remainder of string1 beginning with the\n"
              << "last occurrence of character '"
              << c << "' is: \"" << strrchr(string1, c) << '\"' << std::endl;
    return 0;
}
