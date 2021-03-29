#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <ctime>

using namespace std;

const int MAXRANGE = 1000;
const size_t SIZE = 10;

default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> randomInt(1, MAXRANGE);

int recursiveMinumum(const array<int, SIZE>, int, int);

int main(int argc, char const *argv[])
{
    array<int, SIZE> arr;
    int smallest;

    for (size_t loop = 0; loop < SIZE; ++loop)
        arr[loop] = randomInt(engine);

    cout << "Array members are: \n";
    for (auto items : arr)
        cout << setw(5) << items;
    cout << endl;

    smallest = recursiveMinumum(arr, 0, SIZE - 1);

    cout << "\nSmallest element is: " << smallest << endl;

    return 0;
}

int recursiveMinumum(const array<int, SIZE> arr, int low, int high)
{
    static int smallest = MAXRANGE;
    if (arr[low] < smallest)
        smallest = arr[low];
    return (low == high ? smallest : recursiveMinumum(arr, low + 1, high));
}