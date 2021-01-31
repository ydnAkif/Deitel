#include <iostream>
#include <stdexcept>
#include "Time.hpp"

using namespace std;

int main(int argc, const char *argv[])
{

    Time t(11, 23, 33);
    t.printStandart();
    t.printUniversal();

    Time t2(23, 59, 59);
    t2.printStandart();
    t2.printUniversal();

    return 0;
}
