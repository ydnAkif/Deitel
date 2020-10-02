// 1 to n
#include <iostream>
#include <array>

using namespace std;

const size_t arraySize = 10;

int sumRecursive(const array<int, arraySize> &, size_t);

int main(int argc, char const *argv[])
{
    array<int, arraySize> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int result = sumRecursive(a, arraySize);

    cout << "Result is " << result << endl;

    return 0;
}

int sumRecursive(const array<int, arraySize> &b, size_t size)
{
    if (size == 1)
        return b[0];
    else
        return b[size - 1] + sumRecursive(b, size - 1);
}