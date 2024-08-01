#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
#include "Vector2D.hpp"

class Point2D
{
private:
    float x;
    float y;

public:
    Point2D(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    Point2D operator+(const Point2D &p) const { return Point2D(x + p.getX(), y + p.getY()); }
    
    // Overload the + operator to add a Vector2D to a Point2D
    Point2D operator+(const Vector2D &v) const { return Point2D(x + v.getX(), y + v.getY()); }
    
    Point2D operator-(const Point2D &p) const { return Point2D(x - p.getX(), y - p.getY()); }

    friend std::ostream &operator<<(std::ostream &os, const Point2D &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

#endif // POINT2D_HPP
