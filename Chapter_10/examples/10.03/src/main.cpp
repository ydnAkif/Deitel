#include <iostream>
#include "PhoneNumber.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
    PhoneNumber phone;

    cout << "Enter phone number in the form (123)456-7890:" << endl;

    cin >> phone;

    cout << "The phone number entered was: ";
    cout << phone << endl;

    return 0;
}
