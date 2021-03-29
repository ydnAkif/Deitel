#include <iostream>

int main(int argc, char const *argv[])
{
    double x = 0.001234567;
    double y = 1.946e9;

    std::cout << "Displayed in default format:" << std::endl
              << x << '\t' << y << std::endl;

    std::cout << "\nDisplayed in scientific format:" << std::endl
              << std::scientific << x << '\t' << y << std::endl;

    std::cout << "\nDisplayed in fixed dormat:" << std::endl
              << std::fixed << x << '\t' << y << std::endl;

    return 0;
}
