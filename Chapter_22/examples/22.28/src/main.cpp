#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    double d = atof("99.0");

    std::cout << "The string \"99.0\" converted to double is " << d
              << "\nThe converted value divided by 2 is " << d / 2.0 << std::endl;

    return 0;
}
