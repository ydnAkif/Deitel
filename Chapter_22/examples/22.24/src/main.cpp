#include <iomanip>
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char *s1 = "Happy New Year";
    const char *s2 = "Happy New Year";
    const char *s3 = "Happy Holidays";

    std::cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3
              << "\n\nstrcmp(s1,s2) = " << std::setw(2) << strcmp(s1, s2)
              << "\nstrcmp(s1,s3) = " << std::setw(2) << strcmp(s1, s3)
              << "\nstrcmp(s3,s1) = " << std::setw(2) << strcmp(s3, s1);

    std::cout << "\n\nstrncmp(s1,s3,6) = " << std::setw(2) << strncmp(s1, s3, 6)
              << "\n\nstrncmp(s1,s3,7) = " << std::setw(2) << strncmp(s1, s3, 7)
              << "\nstrncmp(s3,s1,7) = " << std::setw(2) << strncmp(s3, s1, 7) << std::endl;

    return 0;
}
