#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    const size_t vectorSize = 20;
    vector<int> myVector;
    size_t subscript = 0;
    int value = 0;
    bool isDuplicate;

    for (size_t i = 0; i < vectorSize; ++i)
    {
        isDuplicate = false;

        cout << "(" << i + 1 << "/20) Enter value between 10 and 100: ";
        cin >> value;

        if (value >= 10 && value <= 100)
        {
            for (size_t j = 0; j < subscript; ++j)
            {
                if (value == myVector[j])
                {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate)
            {
                myVector.push_back(value);
                ++subscript;
            }
        }
        else
        {
            cout << "Invalid number.\n";
            --i;
        }
    }

    for (size_t index = 0; index < subscript; ++index)
        cout << myVector[index] << setw(4);
    cout << endl;

    return 0;
}