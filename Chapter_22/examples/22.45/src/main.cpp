#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char s[] = "This is a string";

    std::cout << "s = " << s << "\n"
              << std::endl;
    std::cout << "The remainder of s after character 'r' is found is \""
              << static_cast<char *>(memchr(s, 'r', 16)) << '\"' << std::endl;

    return 0;
}
