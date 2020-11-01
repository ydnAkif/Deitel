#include <iostream>

using namespace std;

size_t getSize(double *);

int main()
{
    double numbers[20];

    cout << "The number of bytes in the array is " << sizeof(numbers);

    cout << "\nThe number of bytes returned by getSize is " << getSize(numbers) << endl;

    return 0;
}

size_t getSize(double *ptr)
{
    return sizeof(ptr);
}