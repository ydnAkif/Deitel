#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char x[] = "Happy Birthday to You";
    char y[25];
    char z[15];

    strcpy(y, x);

    std::cout << "The string in array x is: " << x
              << "\nThe string in array y is: " << y << '\n';
    strncpy(z, x, 14);
    z[14] = '\0';

    std::cout << "The string in array z is: " << z << std::endl;

    return 0;
}