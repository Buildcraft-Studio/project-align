#pragma once

#include <iostream>

class Point2D {
public:
    float x, y;

    Point2D(float x = 0, float y = 0) : x(x), y(y) {}

    Point2D operator+(const Point2D& p) const {
        return Point2D(x + p.x, y + p.y);
    }

    Point2D operator-(const Point2D& p) const {
        return Point2D(x - p.x, y - p.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point2D& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
