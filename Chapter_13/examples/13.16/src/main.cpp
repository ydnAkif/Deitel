#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int x = 10000;

    std::cout << x << " printed as int right and left justified\n"
              << "and as hex with internal justification.\n"
              << "Using the default pad character (space):" << std::endl;

    std::cout << std::showbase << std::setw(10) << x << std::endl;

    std::cout << std::left << std::setw(10) << x << std::endl;

    std::cout << std::internal << std::setw(10) << std::hex << x << std::endl
              << std::endl;

    std::cout << "Using various padding characters:" << std::endl;

    std::cout << std::right;
    std::cout.fill('*');
    std::cout << std::setw(10) << std::dec << x << std::endl;

    std::cout << std::left << std::setw(10) << std::setfill('%') << x << std::endl;

    std::cout << std::internal << std::setw(10) << std::setfill('^') << std::hex << x << std::endl;

    return 0;
}
