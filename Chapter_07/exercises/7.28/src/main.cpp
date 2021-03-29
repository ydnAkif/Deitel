#include <iostream>
#include <string>
#include <array>

using namespace std;

const size_t SIZE = 80;

bool testPalindrome(const array<string, SIZE> &, int, int);

int main(int argc, char const *argv[])
{
    string text;
    array<string, SIZE> stringArr, copy;

    int count = 0, copyCount, i;

    cout << "Enter a sentence:\n";

    while ((text = cin.get()) != "\n" && count < SIZE)
        stringArr[count++] = text;

    for (copyCount = 0, i = 0; stringArr[i] != "\0"; ++i)
        if (stringArr[i] != " ")
            copy[copyCount++] = stringArr[i];
    if (testPalindrome(copy, 0, copyCount - 1))
    {
        cout << '\"';
        for (auto index : stringArr)
            cout << index;
        cout << "\" is a palindrome" << endl;
    }
    else
    {
        cout << '\"';
        for (auto index : stringArr)
            cout << index;
        cout << "\" is not a palindrome" << endl;
    }
    return 0;
}

bool testPalindrome(const array<string, SIZE> &arrayString, int left, int right)
{

    if (left == right || left > right)
        return true;
    else if (arrayString[left] != arrayString[right])
        return false;
    else
        return testPalindrome(arrayString, left + 1, right - 1);
}