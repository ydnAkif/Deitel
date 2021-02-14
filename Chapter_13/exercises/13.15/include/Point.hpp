#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
    friend std::ostream &operator<<(std::ostream &, Point &);
    friend std::istream &operator>>(std::istream &, Point &);

private:
    int xCoordinate;
    int yCoordinate;
};

#endif