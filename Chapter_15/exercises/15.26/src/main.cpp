#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>

using std::setiosflags;
using std::setprecision;
using std::setw;

#include <cmath>

using std::sqrt;

#include <bitset>

using std::bitset;

int main(int argc, char const *argv[])
{
    const size_t SIZE = 1024;

    int i, value, counter;

    bitset<SIZE> sieve;

    sieve.flip();

    int finalBit = sqrt(static_cast<double>(sieve.size())) + 1;

    for (i = 2; i < finalBit; ++i)
        if (sieve.test(i))
            for (int j = 2 * i; j < SIZE; j += i)
                sieve.reset(j);

    cout << "The prime numbers in the range 2 to 1023 are:" << endl;

    for (i = 2, counter = 0; i < SIZE; ++i)
    {
        if (sieve.test(i))
        {
            cout << setw(5) << i;

            if (++counter % 12 == 0)
                cout << endl;
        }
    }

    cout << endl;

    cout << endl
         << "Enter a value from 1 to 1023 (-1 to end): ";
    cin >> value;

    while (value != -1)
    {
        if (sieve[value])
            cout << value << " is a prime number." << endl;
        else
        {
            cout << value << " is not a prime number." << endl
                 << "prime factor(s): ";
            for (int f = 2; f < SIZE;)
            {
                if (sieve.test(f) && value % f == 0)
                {
                    cout << f << ' ';

                    value /= f;

                    if (value <= 1)
                        break;
                }
                else
                    ++f;
            }

            cout << endl;
        }

        cout << endl
             << "Enter a value from 1 to 1023 (-1 to end): ";
        cin >> value;
    }
}
