#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <cctype>

const int SIZE = 80;

int main(int argc, char const *argv[])
{
    char array[SIZE], array2[SIZE], c;

    cout << "Enter a sentence to test getline() and get():\n";

    cin.getline(array, SIZE, '*');
    cout << array << '\n';

    cin >> c;
    cout << "The next character in the input is: " << c << '\n';

    cin.get(array2, SIZE, '*');
    cout << array2 << '\n';

    cin >> c;

    cout << "The next character in the input is: " << c << '\n';

    return 0;
}
