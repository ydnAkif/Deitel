#include <iostream>
#include "Time.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Time t;
    unsigned int &hourRef = t.badSetHour(20);
    cout << "Valid hour before modification: " << hourRef;
    hourRef = 30;
    cout << "\nInvalid hour after modification:" << t.getHour();

    t.badSetHour(12) = 74;

    cout << "\n\n*************************************************\n"
         << "POOR PROGRAMMING PRACTICE!!!!!!!!\n"
         << "t.badSetHour( 12 ) as an lvalue, invalid hour: "
         << t.getHour()
         << "\n*************************************************" << endl;

    return 0;
}
