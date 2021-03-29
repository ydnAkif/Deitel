#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "abcdefabcdef";
    const char *string2 = "def";

    std::cout << "string1 = " << string1 << "\nstring2 = " << string2
              << "\n\nThe remainder of string1 beginning with the\n"
              << "first occurrence of string2 is: "
              << strstr(string1, string2) << std::endl;
    return 0;
}
