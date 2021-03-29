#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    long l = atol("1000000");

    std::cout << "The string \"1000000\" converted to long is " << l
              << "\nThe converted value divided by 2 is " << l / 2 << std::endl;

    return 0;
}
