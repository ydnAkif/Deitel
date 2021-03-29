#include <iostream>
using std::cout;
#include <vector>

using std::vector;

template <typename T>
bool palindrome(const vector<T> &vecRef)
{
    typename vector<T>::const_reverse_iterator r = vecRef.rbegin();
    typename vector<T>::const_iterator i = vecRef.begin();

    while (r != vecRef.rend() && i != vecRef.end())
    {
        if (*r != *i)
            return false;
        ++r;
        ++i;
    }
    return true;
}

template <typename T>
void printVector(const vector<T> &vecRef)
{
    typename vector<T>::const_iterator i;

    for (i = vecRef.begin(); i != vecRef.end(); ++i)
        std::cout << *i << ' ';
}

int main()
{
    vector<int> intVector;
    vector<char> charVector;

    int x = 0;

    for (int i = 75; i >= 65; --i)
    {
        intVector.push_back(i);
        charVector.push_back(static_cast<char>(i + x));

        if (i <= 70)
            x += 2;
    }

    printVector(intVector);

    cout << (palindrome(intVector) ? "is " : "is not ")
         << " a palindrome\n";
    printVector(charVector);

    cout << (palindrome(charVector) ? "is " : "is not ")
         << " a palindrome\n";

    return 0;
}
