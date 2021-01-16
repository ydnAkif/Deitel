#include <iostream>
#include "Date.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    const int MAXDAYS = 3000;
    Date d(2, 9, 2013);

    for (int loop = 1; loop <= MAXDAYS; ++loop)
    {
        d.print();
        d.nextDay();
    }

    std::cout << std::endl;

    return 0;
}
