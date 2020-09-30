#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int vectorSize = 20;

void addToVector(vector<int> &, int &);

int main(int argc, char const *argv[])
{
    vector<int> myVector(vectorSize);
    int value;

    for (unsigned int i = 0; i < vectorSize; ++i)
    {
        cout << "(" << i + 1 << "/20) Enter value between 10 and 100: ";
        cin >> value;

        if (value >= 10 && value <= 100)
            addToVector(myVector, value);
        else
            i--;
    }

    for (unsigned int i = 0; i < vectorSize; ++i)
    {
        if (myVector.at(i) != 0)
        {
            cout << myVector.at(i) << setw(4);
        }
    }
    cout << endl;

    return 0;
}

void addToVector(vector<int> &myVector, int &value)
{
    static int subscript = 0;
    bool isDuplicate = false;

    for (unsigned int i = 0; i <= subscript; ++i)
    {
        if (myVector.at(i) == value)
        {
            isDuplicate = true;
            break;
        }
    }

    if (!isDuplicate)
    {
        //myVector.push_back(value);
        myVector.at(subscript) = value;
        ++subscript;
    }
}