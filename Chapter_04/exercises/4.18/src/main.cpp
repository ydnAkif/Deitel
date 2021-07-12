/******************************************************************************

Exercises 4.18

Write a C++ program that uses a while statement and the tab escape sequence \t 
to print the following table of values:

N       10*N        100*N       1000*N
1       10          100         1000
2       20          200         2000
3       30          300         3000
4       40          400         4000
5       50          500         5000

******************************************************************************/

#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int counter{0};

    std::cout << "N\t"
              << "10*N\t"
              << "100*N\t"
              << "1000*N\n";

    while (counter < 5)
    {
        ++counter;
        std::cout << counter << "\t"
                  << 10 * counter << "\t"
                  << 100 * counter << "\t"
                  << 1000 * counter << "\n";
    }

    return 0;
}