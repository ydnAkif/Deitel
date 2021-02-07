#include <iostream>
#include "Complex.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Complex cNum1(4.3, 8.2);
    Complex cNum2(3.3, 1.1);
    Complex cNum3;

    cout << "cNum1: ";
    cNum1.print();
    cout << "\ncNum2: ";
    cNum2.print();
    cout << "\ncNum3: ";
    cNum3.print();

    cNum3 = cNum1 + cNum2;
    cout << "\n\ncNum3 = cNum1 + cNum2:" << endl;
    cNum3.print();
    cout << " = ";
    cNum1.print();
    cout << " + ";
    cNum2.print();

    cNum3 = cNum1 * cNum2;
    cout << "\n\ncNum3 = cNum1 * cNum2:" << endl;
    cNum3.print();
    cout << " = ";
    cNum1.print();
    cout << " * ";
    cNum2.print();

    return 0;
}
