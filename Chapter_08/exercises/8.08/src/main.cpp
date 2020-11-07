#include <iostream>
#include <iomanip>

using namespace std;

const size_t SIZE = 5;

int main(int argc, char const *argv[])
{
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    unsigned int *vPtr;

    for (size_t i = 0; i < SIZE; ++i)
        cout << setw(4) << values[i];
    cout << endl;

    vPtr = values;
    vPtr = &values[0];

    for (size_t i = 0; i < SIZE; ++i)
        cout << setw(4) << *(vPtr + i);
    cout << endl;

    for (size_t i = 0; i < SIZE; ++i)
        cout << setw(4) << *(values + i);
    cout << endl;

    for (size_t i = 0; i < SIZE; ++i)
        cout << setw(4) << vPtr[i];
    cout << endl;

    cout << &*(vPtr + 3) << endl
         << *(vPtr + 3) << endl;

    vPtr = &values[4];
    vPtr -= 4;

    cout << *vPtr << endl;

    return 0;
}
