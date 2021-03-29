#include <iostream>
#include "Date.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Date d1(12, 27, 2010);
    Date d2;

    cout << "d1 is " << d1 << "\nd2 is " << d2;
    cout << "\n\nd1 += 7 is " << (d1 += 7);

    d2.setDate(2, 28, 2008);
    cout << "\n\n d2 is " << d2;
    cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3(7, 13, 2010);

    cout << "\n\nTesting the prefix increment operator:\n"
         << " d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << endl;
    cout << " d3 is " << d3;

    cout << "\n\nTesting the postfix increment operator:\n"
         << " d3 is " << d3 << endl;
    cout << "d3++ is " << d3++ << endl;
    cout << " d3 is " << d3 << endl;

    return 0;
}
