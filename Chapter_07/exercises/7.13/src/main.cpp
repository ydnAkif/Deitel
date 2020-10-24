#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

const size_t arraySize = 20;

int main(int argc, char const *argv[])
{

    array<int, arraySize> a = {};

    int subscript = 0, value;
    bool isDuplicate;

    cout << "Enter 20 integers between 10 and 100:"
         << endl;

    for (size_t i = 0; i < a.size(); ++i)
    {
        isDuplicate = false;

        cin >> value;

        if ((value > 10) && (value < 100))
        {

            for (size_t j = 0; j < subscript; ++j)
                if (value == a[j])
                {
                    isDuplicate = true;
                    break;
                }

            if (!isDuplicate)
                a[subscript++] = value;
        }
        else
        {
            cout << "Invalid Number, must be between 10 and 100 "
                 << endl;
            --i;
        }
    }

    cout << endl
         << "The nonduplicate values are:"
         << endl;

    for (size_t k = 0; a[k] != 0; ++k)
        cout << setw(4) << a[k];

    cout << endl;

    return 0;
}
