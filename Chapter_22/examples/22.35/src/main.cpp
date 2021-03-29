#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "This is a test";
    char character1 = 'a';
    char character2 = 'z';

    if (strchr(string1, character1) != NULL)
        std::cout << '\'' << character1 << "' was found in \""
                  << string1 << "\".\n";
    else
        std::cout << '\'' << character1 << " ' was not found in \""
                  << string1 << "\".\n";

    if (strchr(string1, character2) != NULL)
        std::cout << '\'' << character2 << "' was found in \""
                  << string1 << "\".\n";
    else
        std::cout << '\'' << character2 << " ' was not found in \""
                  << string1 << "\".\n";

    return 0;
}
