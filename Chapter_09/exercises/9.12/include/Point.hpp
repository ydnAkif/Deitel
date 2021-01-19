#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
    int x;
    int y;

public:
    explicit Point(int = 0, int = 0);
    ~Point();

    void setX(int);
    void setY(int);

    int getX() const;
    int getY() const;
};

#endif