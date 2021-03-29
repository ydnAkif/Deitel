#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
private:
    double lenght;
    double width;

public:
    Rectangle(double = 1.0, double = 1.0);
    ~Rectangle();

    void setWidth(double);
    void setLenght(double);

    double getLenght() const;
    double getWidth() const;
    double getPerimeter() const;
    double getArea() const;
};

#endif