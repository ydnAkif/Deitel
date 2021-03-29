#include <iostream>
#include <cmath>
#include "Rectangle.hpp"

Rectangle::Rectangle(Point topL, Point botL, Point topR, Point botR, char c, char pc)
{
    setRectangle(topL, botL, topR, botR);
    setFillCharacter(c);
    setPerimeterCharacter(pc);
}

Rectangle::~Rectangle() {}

void Rectangle::setRectangle(Point topL, Point botL, Point topR, Point botR)
{
    if (topL.getX() <= 20.0 && topL.getY() <= 20.0 &&
        topR.getX() <= 20.0 && topR.getY() <= 20.0 &&
        botL.getX() <= 20.0 && botL.getY() <= 20.0 &&
        botR.getX() <= 20.0 && botR.getY() <= 20.0)
    {
        if (topL.getX() != botL.getX() || topR.getX() != botR.getX() ||
            topL.getY() != topR.getY() || botL.getY() != botR.getY())
        {
            throw std::invalid_argument(" coordinates do not match.");
            setValid(false);
        }
        else
        {
            topLeft = topL;
            topRight = topR;
            bottomLeft = botL;
            bottomRight = botR;

            if (isSquare())
                std::cout << "The rectangle is a square.\n\n";
            setValid(true);
        }
    }
}

void Rectangle::setFillCharacter(char c) { fillChar = c; }

void Rectangle::setPerimeterCharacter(char c) { periChar = c; }

void Rectangle::setValid(bool v) { valid = v; }

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

bool Rectangle::isValid() { return valid; }

void Rectangle::draw()
{
    for (double y = 25; y >= 0; --y)
    {
        for (double x = 0; x <= 25; ++x)
        {
            if ((bottomLeft.getX() == x && bottomLeft.getY() == y) ||
                (topLeft.getX() == x && topLeft.getY() == y))
            {
                while (x <= bottomRight.getX())
                {
                    std::cout << periChar;
                    ++x;
                }
                std::cout << '.';
            }
            else if ((x <= topLeft.getX() && x >= bottomLeft.getX()) &&
                     (topLeft.getY() >= y && bottomLeft.getY() <= y))
            {
                std::cout << periChar;
                for (x++; x < bottomRight.getX();)
                {
                    std::cout << fillChar;
                    ++x;
                }

                std::cout << periChar;
            }
            else
                std::cout << '.';
        }

        std::cout << std::endl;
    }
}