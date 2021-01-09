#include <iostream>
#include "Date.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Date date1(8, 1, 2021);
    Date date2;

    cout << "date1 = ";
    date1.print();

    cout << "\ndate2 = ";
    date2.print();

    date2 = date1;

    cout << "\n\nAfter default memberwise assignment, date2 = ";
    date2.print();
    cout << endl;

    return 0;
}
