#include <iostream>
#include <iomanip>
#include "Rectangle.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Point tl(1, 10);
    Point bl(1, 1);
    Point tr(5, 10);
    Point br(5, 1);

    try
    {
        Rectangle r1(tl, bl, tr, br);

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
