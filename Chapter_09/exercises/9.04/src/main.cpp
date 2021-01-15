#include <iostream>
#include "Time.hpp"

int main(int argc, char const *argv[])
{
    Time time1;
    Time time2(12, 12, 12);

    std::cout << "time1 Universal Time: ";
    time1.printUniversal();
    std::cout << std::endl;
    std::cout << "time1 Standard  Time: ";
    time1.printStandard();

    std::cout << "\n\ntime2 Universal Time: ";
    time2.printUniversal();
    std::cout << std::endl;
    std::cout << "time2 Standard  Time: ";
    time2.printStandard();

    return 0;
}
