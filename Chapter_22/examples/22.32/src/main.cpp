#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "-1234567abc";
    char *remainderPtr = nullptr;
    long x = strtol(string1, &remainderPtr, 0);

    std::cout << "The original string is \"" << string1
              << "\"\nThe converted value is " << x
              << "\nThe remainder of the original string is \"" << remainderPtr
              << "\"\nThe converted value plus 567 is " << x + 567 << std::endl;

    return 0;
}
