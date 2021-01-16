// Fig. 9.27: main.cpp
// Cascading member-function calls with the this pointer.
#include <iostream>
#include "Time.hpp" // Time class definition
using namespace std;

int main()
{
   Time t; // create Time object

   t.setHour(18).setMinute(30).setSecond(22); // cascaded function calls

   // output time in universal and standard formats
   cout << "Universal time: " << t.toUniversalString()
        << "\nStandard time: " << t.toStandardString();

   // cascaded function calls
   cout << "\n\nNew standard time: "
        << t.setTime(20, 20, 20).toStandardString() << endl;
}
