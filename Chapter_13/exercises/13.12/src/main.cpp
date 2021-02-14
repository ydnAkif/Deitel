#include <iostream>
using std::cout;
using std::ios;
#include <iomanip>
using std::resetiosflags;
using std::setiosflags;
using std::setprecision;
using std::setw;

int main(int argc, char const *argv[])
{
    double celcius;

    cout << setw(20) << "Fahrenheit " << setw(20) << "Celcius\n"
         << setiosflags(ios::fixed | ios::showpoint);

    for (int fahrenheit = 0; fahrenheit <= 212; ++fahrenheit)
    {
        celcius = 5.0 / 9.0 * (fahrenheit - 32);
        cout << setw(15) << resetiosflags(ios::showpos) << fahrenheit
             << setw(23) << setprecision(3) << setiosflags(ios::showpos)
             << celcius << '\n';
    }

    return 0;
}
