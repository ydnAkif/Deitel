#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "abcdefghijklmnopqrstuvwxyz";
    const char *string2 = "four";
    const char *string3 = "Boston";

    std::cout << "The length of \"" << string1 << "\" is " << strlen(string1)
              << "\nthe length of \"" << string2 << "\" is " << strlen(string2)
              << "\nthe length of \"" << string3 << "\" is " << strlen(string3)
              << std::endl;

    return 0;
}
