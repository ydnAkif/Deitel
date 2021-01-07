#include <iostream>
#include <stdexcept>
#include "Time.hpp"

using namespace std;

int main(int argc, const char *argv[])
{

    Time t;

    cout << "The initial universal time is ";
    t.printUniversal();
    cout << "\nThe initial standard time is ";
    t.printStandart();

    t.setTime(13, 27, 6);

    cout << "\n\nUniversal time after setTime is ";
    t.printUniversal();
    cout << "\nStandart time after setTime is ";
    t.printStandart();

    try
    {
        t.setTime(99, 99, 99);
    }
    catch (invalid_argument &e)
    {
        cout << "\nException: " << e.what() << endl;
    }

    cout << "\n\nAfter attempting invalid settings:"
         << "\nUniversal time: ";
    t.printUniversal();
    cout << "\nStandart time: ";
    t.printStandart();
    cout << endl;

    return 0;
}
