#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "The value is 3.14159";
    const char *string2 = "aehils Tuv";

    std::cout << "string1 = " << string1 << "\nstring2 = " << string2
              << "\n\nThe length of the initial segment of string1\n"
              << "containing only characters from string2 = "
              << strspn(string1, string2) << std::endl;
    return 0;
}
