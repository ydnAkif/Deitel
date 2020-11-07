#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{

    long int value1 = 200'000;
    long int value2;

    long *longPtr;

    longPtr = &value1;

    cout << *longPtr << endl;

    value2 = *longPtr;

    cout << value2 << endl;

    cout << &value1 << endl;

    cout << longPtr << endl;

    return 0;
}
