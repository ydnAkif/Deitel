#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Point.hpp"

class Rectangle
{
private:
    Point topLeft;
    Point topRight;
    Point bottomLeft;
    Point bottomRight;

    /* 
    
    topleft---------------------TopRight
    -                                  -
    -                                  -
    -                                  -
    -                                  -
    BottomLeft---------------BottomRight
    
    
    */

public:
    Rectangle(Point, Point, Point, Point);
    ~Rectangle();

    void setRectangle(Point, Point, Point, Point);

    double getLength() const;
    double getWidth() const;
    double getPerimeter() const;
    double getArea() const;

    bool isSquare();
};

#endif