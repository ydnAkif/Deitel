#include <iostream>
#include "Time.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Time wakeUp(6, 45, 0);
    const Time noon(12, 0, 0);

    wakeUp.setHour(18);
    noon.setHour(12);

    wakeUp.getHour();
    noon.getMinute();
    noon.printUniversal();
    noon.printStandart();

    return 0;
}
