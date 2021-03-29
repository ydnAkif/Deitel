#include <iostream>
#include "Time.hpp"

int main(int argc, char const *argv[])
{
    Time t;
    t.printStandard();
    std::cout << std::endl;
    t.printUniversal();

    return 0;
}
