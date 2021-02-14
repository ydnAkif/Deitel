#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    double x = 100.453627;

    std::cout << std::setiosflags(std::ios::fixed);

    for (size_t i = 0; i <= 5; ++i)
    {
        std::cout << std::setprecision(i) << "Rounded to " << i << " digit(s) is " << x << std::endl;
    }

    return 0;
}
