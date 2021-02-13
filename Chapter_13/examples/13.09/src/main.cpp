#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char const *argv[])
{
    double root2 = std::sqrt(2.0);
    int places;

    std::cout << "Square root of 2 with precisions 0-9." << std::endl
              << "Precision set by ios_base member function "
              << "precision:" << std::endl;
    std::cout << std::fixed;

    for (places = 0; places <= 9; ++places)
    {
        std::cout.precision(places);
        std::cout << root2 << std::endl;
    }

    std::cout << "\nPrecision set by stream manipulator "
              << "setprecision:" << std::endl;
    for (places = 0; places <= 9; ++places)
        std::cout << std::setprecision(places) << root2 << std::endl;

    return 0;
}
