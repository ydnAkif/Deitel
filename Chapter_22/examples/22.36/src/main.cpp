#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "The value is 3.14159";
    const char *string2 = "1234567890";

    std::cout << "string1 = " << string1 << "\nstring2 = " << string2
              << "\n\nThe length of the initial segment of string1"
              << "\n  containing no charecters from string2 = "
              << strcspn(string1, string2) << std::endl;

    return 0;
}
