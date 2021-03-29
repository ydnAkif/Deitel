#include <iostream>
#include <iomanip>
#include <cstring>

int main(int argc, char const *argv[])
{
    char s1[] = "ABCDEFG";
    char s2[] = "ABCDXYZ";

    std::cout << "s1 = " << s1 << "\ns2 = " << s2 << std::endl
              << "\nmemcmp(s1,s2,4) = " << std::setw(3) << memcmp(s1, s2, 4)
              << "\nmemcmp(s1,s2,7) = " << std::setw(3) << memcmp(s1, s2, 7)
              << "\nmemcmp(s2,s1,7) = " << std::setw(3) << memcmp(s2, s1, 7)
              << std::endl;

    return 0;
}
