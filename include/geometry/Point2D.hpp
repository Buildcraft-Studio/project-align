#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>

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

    Point2D operator+(const Point2D &p) const { return Point2D(x + p.x, y + p.y); }
    Point2D operator-(const Point2D &p) const { return Point2D(x - p.x, y - p.y); }

    friend std::ostream &operator<<(std::ostream &os, const Point2D &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

#endif // POINT2D_HPP
