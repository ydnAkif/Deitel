#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Rectangle.hpp"

using namespace std;

int main(int argc, const char *argv[])
{

    Rectangle a, b(4.0, 5.0);

    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << setprecision(1);

    // output a
    cout << "a: lenght = " << a.getLenght()
         << "; width = " << a.getWidth()
         << "; perimeter = " << a.getPerimeter()
         << "; area = " << a.getArea() << endl;
    cout << "b: lenght = " << b.getLenght()
         << "; width = " << b.getWidth()
         << "; perimeter = " << b.getPerimeter()
         << "; area = " << b.getArea() << endl;

    try
    {
        Rectangle c(10.0, 48.0);
        cout << "c: lenght = " << c.getLenght()
             << "; width = " << c.getWidth()
             << "; perimeter = " << c.getPerimeter()
             << "; area = " << c.getArea() << endl;
    }
    catch (invalid_argument &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}
