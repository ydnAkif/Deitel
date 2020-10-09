#include <iostream>
#include <array>
#include <string>

using namespace std;

const size_t SIZE = 30;

void stringReverse(const string &);

int main(int argc, char const *argv[])
{
    string strArray = "Print this string backwards.";

    for (size_t loop = 0; loop < SIZE; ++loop)
        cout << strArray[loop];
    cout << endl;

    stringReverse(strArray);
    cout << endl;

    return 0;
}

void stringReverse(const string &strArray)
{
    if (strArray[0] == '\0')
        return;
    stringReverse(&strArray[1]);
    cout << strArray[0];
}