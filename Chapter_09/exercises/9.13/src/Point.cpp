#include "Point.hpp"

Point::Point(int X, int Y)
{
    setX(X);
    setY(Y);
}

Point::~Point() {}

void Point::setX(int X)
{
    x = X;
}

void Point::setY(int Y)
{
    y = Y;
}

int Point::getX() const { return x; }

int Point::getY() const { return y; }