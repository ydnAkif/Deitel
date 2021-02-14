#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int x = 12345;

    std::cout << "Default is right justified:" << std::endl
              << std::setw(10) << x;
    std::cout << "\n\nUse std::left to left justify x:\n"
              << std::left << std::setw(10) << x;
    std::cout << "\n\nUse std::right to right justify x:\n"
              << std::right << std::setw(10) << x << std::endl;

    return 0;
}
