#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(double w, double l)
{
    setWidth(w);
    setLenght(l);
}

Rectangle::~Rectangle() {}

void Rectangle::setWidth(double w)
{
    if (w < 20 && w > 0)
        width = w;
    else
        throw std::invalid_argument("width must be 0-20");
}

void Rectangle::setLenght(double l)
{
    if (l < 20 && l > 0)
        lenght = l;
    else
        throw std::invalid_argument("length must be 0-20");
}

double Rectangle::getWidth() const { return width; }

double Rectangle::getLenght() const { return lenght; }

double Rectangle::getPerimeter() const { return 2 * (width + lenght); }

double Rectangle::getArea() const { return (width * lenght); }
