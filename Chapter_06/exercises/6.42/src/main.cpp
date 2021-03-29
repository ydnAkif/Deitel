#include <iostream>
#include <cmath>

struct Points
{
    Points(double X, double Y)
    {
        x = X;
        y = Y;
    }
    double x;
    double y;
};

double getDistance(Points, Points);

int main()
{
    double x1, y1, x2, y2;
    Points pointsA(x1, y1);
    Points pointsB(x2, y2);
    std::cout << "A Program that calculates the distance between two points"
              << std::endl
              << std::endl;
    std::cout << "Enter two points (x1,y1) and (x2,y2) : ";
    std::cin >> pointsA.x >> pointsA.y >> pointsB.x >> pointsB.y;

    std::cout << "The Distance between ("
              << pointsA.x
              << ", "
              << pointsA.y
              << ") and ("
              << pointsB.x
              << ", "
              << pointsB.y
              << ") = "
              << getDistance(pointsA, pointsB)
              << std::endl;
    return 0;
}

double getDistance(Points pointsA, Points pointsB)
{
    double diffX = pointsA.x - pointsB.x;
    double diffY = pointsA.y - pointsB.y;

    return sqrt(pow(diffX, 2) + pow(diffY, 2));
}