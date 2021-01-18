#include <iostream>
#include "DateAndTime.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    DateAndTime dt(27, 11, 2020, 23, 59, 57);

    for (int ticks = 1; ticks < 30; ++ticks)
    {
        //cout << "Universal time: ";
        //dt.printUniversal();
        cout << "Standard time: ";
        dt.printStandard();
        dt.tick();
    }
    cout << endl;

    return 0;
}
