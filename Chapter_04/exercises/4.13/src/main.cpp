/******************************************************************************

Exercises 4.13

(Gas Mileage) Drivers are concerned with the mileage obtained by their 
automobiles. One driver has kept track of several trips by recording miles 
driven and gallons used for each trip. Develop a C++ program that uses a while 
statement to input the miles driven and gallons used for each trip. The program 
should calculate and display the miles per gallon obtained for each trip and 
print the combined miles per gallon obtained for all tankfuls up to this point.

******************************************************************************/


#include "GasMileage.hpp"

static const int QUIT = -1;
int main()
{
    GasMileage gm;
    while (gm.getMilesDriven() != QUIT)
    {
        gm.run();
    }

    return 0;
}
