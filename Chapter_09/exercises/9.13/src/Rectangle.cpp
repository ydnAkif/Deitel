#include <iostream>
#include <cmath>
#include "Rectangle.hpp"

Rectangle::Rectangle(Point topL, Point botL, Point topR, Point botR)
{
    setRectangle(topL, botL, topR, botR);
}

Rectangle::~Rectangle() {}

void Rectangle::setRectangle(Point topL, Point botL, Point topR, Point botR)
{
    if (topL.getX() < 20.0 && topL.getY() < 20.0 &&
        topR.getX() < 20.0 && topR.getY() < 20.0 &&
        botL.getX() < 20.0 && botL.getY() < 20.0 &&
        botR.getX() < 20.0 && botR.getY() < 20.0)
    {
        if (topL.getX() != botL.getX() || topR.getX() != botR.getX() ||
            topL.getY() != topR.getY() || botL.getY() != botR.getY())
            throw std::invalid_argument(" coordinates do not match.");
        else
        {
            topLeft = topL;
            topRight = topR;
            bottomLeft = botL;
            bottomRight = botR;

            if (isSquare())
                std::cout << "The rectangle is a square.\n\n";
        }
    }
}

double Rectangle::getWidth() const { return fabs(bottomRight.getY() - topRight.getY()); }

double Rectangle::getLength() const { return fabs(topRight.getX() - topLeft.getX()); }

double Rectangle::getPerimeter() const { return 2 * (getWidth() + getLength()); }

double Rectangle::getArea() const { return (getWidth() * getLength()); }

bool Rectangle::isSquare()
{
    if (getLength() == getWidth())
        return true;
    else
        return false;
}