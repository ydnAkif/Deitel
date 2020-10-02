// Ex. 7.20: Ex07_20.cpp
// What does this program do?
#include <iostream>
#include <array>
using namespace std;

const size_t arraySize = 10;
void someFunction(const array<int, arraySize> &, size_t); // prototype

int main()
{
    array<int, arraySize> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "The values in the array are:" << endl;
    someFunction(a, 0);
    cout << endl;
} // end main

// What does this function do?
void someFunction(const array<int, arraySize> &b, size_t current)
{
    if (current < b.size())
    {
        someFunction(b, current + 1);
        cout << b[current] << " ";
    } // end if
} // end function someFunction