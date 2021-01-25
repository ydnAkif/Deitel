#include <iostream>
#include <iomanip>
#include "Rectangle.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Point tl(12, 20);
    Point bl(12, 12);
    Point tr(18, 20);
    Point br(18, 12);

    try
    {
        Rectangle r1(tl, bl, tr, br, '?', '*');
        if (r1.isValid())
        {
            r1.draw();
        }

        std::cout << "Width: " << r1.getWidth() << "\nLength: " << r1.getLength()
                  << "\nArea: " << r1.getArea()
                  << "\nPerimeter: " << r1.getPerimeter() << std::endl;
    }
    catch (invalid_argument &e)
    {
        std::cout << "Exception" << e.what() << '\n';
    }

    return 0;
}
