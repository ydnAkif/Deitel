#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char x[] = "Home Sweet Home";

    std::cout << "The string in array x before memmove is: " << x;
    std::cout << "\nThe string in array x after memmove is: "
              << static_cast<char *>(memmove(x, &x[5], 10)) << std::endl;
    return 0;
}
