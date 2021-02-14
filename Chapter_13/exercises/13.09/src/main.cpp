#include <iostream>

#include <iomanip>

int main(int argc, char const *argv[])
{
    int x = 12345;
    double y = 1.2345;

    for (int loop = 0; loop <= 10; ++loop)
        std::cout << x << "  printed in a field of size " << loop << " is "
                  << std::setw(loop) << x << '\n'
                  << y << " printed in a field "
                  << "of size " << loop << " is "
                  << std::setw(loop) << y << '\n';

    return 0;
}
