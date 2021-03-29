#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char s1[17] = {};
    char s2[] = "Copy this string";

    memcpy(s1, s2, 17);

    std::cout << "After s2 is copied into s1 with memcpy,\n"
              << "s1 contains \"" << s1 << '\"' << std::endl;

    return 0;
}
