#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "This is a test";
    const char *string2 = "beware";

    std::cout << "Of the characters in \"" << string2 << "\"\n'"
              << *strpbrk(string1, string2) << "\' is the first character "
              << "to appear in\n\"" << string1 << '\"' << std::endl;
    

    return 0;
}
