#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char string1[15] = "BBBBBBBBBBBBBB";

    std::cout << "string1 = " << string1 << std::endl;
    std::cout << "string1 after memset = "
              << static_cast<char *>(memset(string1, 'b', 7)) << std::endl;
    return 0;
}
