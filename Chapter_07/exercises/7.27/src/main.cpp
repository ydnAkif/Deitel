#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

using namespace std;

const size_t SIZE = 1000;

int main(int argc, char const *argv[])
{
    array<int, SIZE> arrPrimes;
    int count = 0;

    for (size_t k = 0; k < SIZE; ++k)
    {
        arrPrimes[k] = 1;
    }

    for (size_t i = 1; i < SIZE; ++i)
    {
        if (arrPrimes[i] == 1 && i != 1)
            for (size_t j = i; j <= SIZE; ++j)
                if (j % i == 0 && j != i)
                    arrPrimes[j] = 0;
    }

    for (size_t q = 2; q < SIZE; ++q)
    {
        if (arrPrimes[q] == 1)
        {
            cout << right << setw(3) << q << " is a prime  number.\n";
            ++count;
        }
    }
    cout << "\nA total of " << count << " prime numbers were found." << endl;

    return 0;
}
