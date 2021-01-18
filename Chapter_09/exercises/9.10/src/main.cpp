#include <iostream>
#include "Time.hpp"

using namespace std;

int main(int argc, const char *argv[])
{

    Time t;
    Time::error_status es = t.setTime(12, 10, 10);
    t.printStandart();
    std::cout << std::endl;
    t.printSetError(es);

    es = t.setHour(33);
    t.printSetError(es);

    es = t.setMinute(128);
    t.printSetError(es);

    es = t.setSecond(-5);
    t.printSetError(es);

    t.printStandart();
    std::cout << std::endl;

    return 0;
}
