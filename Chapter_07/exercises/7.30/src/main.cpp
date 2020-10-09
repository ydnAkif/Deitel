#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

const size_t SIZE = 20;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randomInt(1, 100);

void printArray(const array<int, SIZE>, int, int);

int main(int argc, char const *argv[])
{
    const int MAXNUMBER = 500;

    array<int, SIZE> arr;
    for (size_t loop = 0; loop < SIZE; ++loop)
        arr[loop] = randomInt(engine);
    cout << " Array values printed in main:\n";

    for (size_t j = 0; j < SIZE; ++j)
        cout << setw(5) << arr[j];

    cout << "\n\nArray values printed in printArray:\n";
    printArray(arr, 0, SIZE - 1);
    cout << endl;

    return 0;
}

void printArray(const array<int, SIZE> arr, int low, int high)
{
    cout << setw(5) << arr[low];
    if (low == high)
        return;
    else
        printArray(arr, low + 1, high);
}