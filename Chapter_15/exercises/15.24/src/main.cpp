#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <iomanip>

using std::setw;

#include <cmath>

using std::sqrt;

#include <bitset>
using std::bitset;

int main()
{
    const int SIZE = 1024;
    int value;

    bitset<SIZE> sieve;

    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);

    int finalBit = sqrt(static_cast<double>(sieve.size())) + 1;

    for (int i = 2; i < finalBit; ++i)
    {
        if (sieve.test(i))
        {
            for (int j = 2 * i; j < SIZE; j += i)
                sieve.reset(j);
        }
    }

    cout << "The prime numbers in the range 2 to 1023 are:\n";

    for (int k = 2, counter = 1; k < SIZE; ++k)
    {
        if (sieve.test(k))
        {
            cout << setw(5) << k;

            if (counter++ % 12 == 0)
                cout << endl;
        }
    }

    cout << endl;

    cout << "\nEnter a value from 2 to 1023(-1 to end): ";
    cin >> value;

    while (value != -1)
    {
        if (sieve[value])
            cout << value << " is a prime number." << endl;
        else
            cout << value << " is not a prime number." << endl;

        cout << "\nEnter a value from 2 to 1023(-1 to end): ";
        cin >> value;
    }

    return 0;
}
