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
    char fillChar;
    char periChar;
    bool valid;

    /* 
    
    topleft---------------------TopRight
    -                                  -
    -                                  -
    -                                  -
    -                                  -
    BottomLeft---------------BottomRight
    
    
    */

public:
    Rectangle(Point, Point, Point, Point, char, char);
    ~Rectangle();

    void setRectangle(Point, Point, Point, Point);
    void setFillCharacter(char);
    void setPerimeterCharacter(char);
    void setValid(bool);

    double getLength() const;
    double getWidth() const;
    double getPerimeter() const;
    double getArea() const;

    bool isSquare();
    bool isValid();
    void draw();
};

#endif