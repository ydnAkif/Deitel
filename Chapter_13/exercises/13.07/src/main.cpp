#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>

using std::dec;
using std::hex;
using std::oct;
using std::setiosflags;

int main(int argc, char const *argv[])
{
    int integer;

    cout << "Enter an integer: ";
    cin >> integer;

    cout << setiosflags(ios::showbase) << "As a decimal number " << dec
         << integer << "\nAs an octal number " << oct
         << integer << "\nAs an hexadecimal number " << hex
         << integer << endl;

    cout << "\nEnter an integer in hexadecimal format\n";
    cin >> hex >> integer;

    cout << setiosflags(ios::showbase) << "As a decimal number " << dec
         << integer << "\nAs an octal number " << oct
         << integer << "\nAs an hexadecimal number " << hex << integer << endl;

    cout << "\nEnter an integer in octal format\n";
    cin >> oct >> integer;

    cout << setiosflags(ios::showbase) << "As a decimal number " << dec
         << integer << "\nAs an octal number " << oct
         << integer << "\nAs an hexadecimal number " << hex << integer << endl;

    return 0;
}
