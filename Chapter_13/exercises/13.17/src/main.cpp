#include <iostream>

using std::cout;
using std::endl;
using std::ios;

#include <iomanip>

using std::dec;
using std::hex;
using std::oct;
using std::setiosflags;
using std::setw;

int main(int argc, char const *argv[])
{
    cout << setw(7) << "Decimal" << setw(9) << "Octal" << setw(15)
         << "Hexadecimal" << setw(13) << "Character"
         << setiosflags(ios::showbase) << '\n';

    for (int loop = 33; loop <= 126; ++loop)
        cout << setw(7) << dec << loop << setw(9) << oct << loop
             << setw(15) << hex << loop << setw(13)
             << static_cast<char>(loop) << endl;

    return 0;
}
