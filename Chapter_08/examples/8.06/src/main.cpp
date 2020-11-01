#include <iostream>

using namespace std;

int cubeByValue(int);

int main()
{
    int number = 5;

    cout << "The original value of number is " << number;

    number = cubeByValue(number);

    cout << "\nThe new value of number is " << number << endl;

    return 0;
}

int cubeByValue(int n)
{
    return n * n * n;
}