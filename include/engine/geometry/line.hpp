#ifndef LINE_HPP
#define LINE_HPP

#include "point.hpp"  // Include point header to use Point class

class Line {
public:
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    // Declare the length function
    float length() const;

private:
    Point p1;
    Point p2;
};

#endif // LINE_HPP
