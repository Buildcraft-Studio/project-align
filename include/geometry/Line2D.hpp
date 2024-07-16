#ifndef LINE2D_HPP
#define LINE2D_HPP

#include "Point2D.hpp"

class Line2D {
public:
    float a, b, c; // Coefficients for the line equation ax + by + c = 0

    Line2D(float a = 1, float b = -1, float c = 0) : a(a), b(b), c(c) {}

    // Constructor to create a line from two points
    Line2D(const Point2D& p1, const Point2D& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = a * p1.x + b * p1.y;
    }

    bool isPointOnLine(const Point2D& p) const {
        return (a * p.x + b * p.y + c) == 0;
    }
};

#endif // LINE2D_HPP