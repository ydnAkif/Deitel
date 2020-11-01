#include <iostream>

using namespace std;

int main()
{

    int a = 7;
    int *aPtr = &a;

    cout << "The address of a is " << &a << "\nThe value of aPtr is "
         << aPtr;

    cout << "\n\nThe value of a is " << a << "\nThe value of *aPtr is "
         << *aPtr;

    return 0;
}
