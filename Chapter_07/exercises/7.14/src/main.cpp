#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    const size_t vectorSize = 20;
    vector<int> myVector;
    int subscript = 0;
    int value = 0;
    bool isDuplicate;

    for (unsigned int i = 0; i < vectorSize; ++i)
    {
        isDuplicate = false;

        cout << "(" << i + 1 << "/20) Enter value between 10 and 100: ";
        cin >> value;

        if (value >= 10 && value <= 100)
        {
            for (unsigned int i = 0; i < myVector.size(); ++i)
            {
                if (value == myVector[i])
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
            i--;
    }

    for (unsigned int index = 0; index < subscript; ++index)
        cout << myVector[index] << setw(4);
    cout << endl;

    return 0;
}