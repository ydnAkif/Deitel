#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char s1[20] = "Happy ";
    char s2[] = "New Year ";
    char s3[40] = "";

    std::cout << "s1= " << s1 << "\ns2 = " << s2;

    strcat(s1, s2);

    std::cout << "\n\nAfter strcat(s1,s2):\ns1 = " << s1 << "\ns2 = " << s2;

    strncat(s3, s1, 6);
    std::cout << "\n\nAfter strncat(s3,s1,6):\ns1 = " << s1 << "\ns3 = " << s3;

    strcat(s3, s1);

    std::cout << "\n\nAfter strcat(s3,s1):\ns1 = " << s1 << "\ns3 = " << s3 << std::endl;

    return 0;
}
