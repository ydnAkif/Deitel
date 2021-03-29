#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

const size_t arraySize = 20;

int main(int argc, char const *argv[])
{

    array<int, arraySize> myArray = {};

    size_t subscript = 0;
    int value;
    bool isDuplicate;

    for (size_t i = 0; i < myArray.size(); ++i)
    {
        isDuplicate = false;

        cout << "(" << i + 1 << "/20) Enter value between 10 and 100: ";
        cin >> value;

        if ((value >= 10) && (value <= 100))
        {
            for (size_t j = 0; j < subscript; ++j)
            {
                if (value == myArray[j])
                {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate)
                myArray[subscript++] = value;
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

    for (size_t index = 0; index < subscript; ++index)
        cout << myArray[index] << setw(4);
    cout << endl;

    return 0;
}
