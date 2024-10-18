#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "polygon.hpp"

class Rectangle : public Polygon {
public:
    Rectangle(float width, float height, const Point& origin);
    float area() const;

private:
    float width;
    float height;
    Point origin; // Represents the bottom-left corner of the rectangle
};

#endif // RECTANGLE_HPP
