#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *string1 = "51.2% are admitted";
    char *stringPtr = nullptr;

    double d = strtod(string1, &stringPtr);

    std::cout << "The string \"" << string1
              << "\" is converted to the\ndouble value " << d
              << " and the string \"" << stringPtr << "\"" << std::endl;

    return 0;
}
